#include "InstallerUtil.h"
#include "InstallerMain.h"
#include <stdio.h>
#include <windows.h>

int tstrcasecmp(const TCHAR *str1, const TCHAR *str2)
{
#if defined _UNICODE
	return _wcsicmp(str1, str2);
#else
	return _stricmp(str1, str2);
#endif
}

size_t AnsiToUnicode(const char *str, wchar_t *buffer, size_t maxchars)
{
	if (maxchars < 1)
	{
		return 0;
	}

	size_t total = 
		(size_t)MultiByteToWideChar(CP_UTF8,
		0,
		str,
		-1,
		buffer,
		(int)maxchars);

	return total;
}

bool IsWhiteSpaceA(const char *stream)
{
	char c = *stream;
	if (c & (1<<7))
	{
		return false;
	}
	else
	{
		return isspace(c) != 0;
	}
}

int BreakStringA(const char *str, char *out, size_t maxchars)
{
	const char *inptr = str;
	while (*inptr != '\0' && IsWhiteSpaceA(inptr))
	{
		inptr++;
	}

	if (*inptr == '\0')
	{
		if (maxchars)
		{
			*out = '\0';
		}
		return -1;
	}

	const char *start, *end = NULL;

	bool quoted = (*inptr == '"');
	if (quoted)
	{
		inptr++;
		start = inptr;
		/* Read input until we reach a quote. */
		while (*inptr != '\0' && *inptr != '"')
		{
			/* Update the end point, increment the stream. */
			end = inptr++;
		}
		/* Read one more token if we reached an end quote */
		if (*inptr == '"')
		{
			inptr++;
		}
	}
	else
	{
		start = inptr;
		/* Read input until we reach a space */
		while (*inptr != '\0' && !IsWhiteSpaceA(inptr))
		{
			/* Update the end point, increment the stream. */
			end = inptr++;
		}
	}

	/* Copy the string we found, if necessary */
	if (end == NULL)
	{
		if (maxchars)
		{
			*out = '\0';
		}
	}
	else if (maxchars)
	{
		char *outptr = out;
		maxchars--;
		for (const char *ptr=start;
			(ptr <= end) && ((unsigned)(outptr - out) < (maxchars));
			ptr++, outptr++)
			{
			*outptr = *ptr;
		}
		*outptr = '\0';
	}

	/* Consume more of the string until we reach non-whitespace */
	while (*inptr != '\0' && IsWhiteSpaceA(inptr))
	{
		inptr++;
	}

	return (int)(inptr - str);
}

size_t UTIL_Format(TCHAR *buffer, size_t count, const TCHAR *fmt, ...)
{
	va_list ap;
	size_t len;
	
	va_start(ap, fmt);
	len = UTIL_FormatArgs(buffer, count, fmt, ap);
	va_end(ap);

	if (len >= count)
	{
		len = count - 1;
		buffer[len] = '\0';
	}

	return len;
}

size_t UTIL_FormatArgs(TCHAR *buffer, size_t count, const TCHAR *fmt, va_list ap)
{
	size_t len = _vsntprintf(buffer, count, fmt, ap);

	if (len >= count)
	{
		len = count - 1;
		buffer[len] = '\0';
	}

	return len;
}

size_t UTIL_PathFormat(TCHAR *buffer, size_t count, const TCHAR *fmt, ...)
{
	va_list ap;
	size_t len;

	va_start(ap, fmt);
	len = UTIL_FormatArgs(buffer, count, fmt, ap);
	va_end(ap);

	for (size_t i = 0; i < len; i++)
	{
		if (buffer[i] == '/')
		{
			buffer[i] = '\\';
		}
	}

	return len;
}

const TCHAR *GetFileFromPath(const TCHAR *path)
{
	size_t len = _tcslen(path);

	for (size_t i = len - 1;
		 i >= 0 && i < len;
		 i--)
	{
		if (path[i] == '\\' || path[i] == '/')
		{
			return &path[i+1];
		}
	}

	return NULL;
}

void GenerateErrorMessage(DWORD err, TCHAR *buffer, size_t maxchars)
{
	if (FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		err,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		buffer,
		(DWORD)maxchars,
		NULL) == 0)
	{
		UTIL_Format(buffer, maxchars, _T("Unknown error"));
	}
}

INT_PTR AskToExit(HWND hWnd)
{
	TCHAR verify_exit[100];

	if (LoadString(g_hInstance,
		IDS_VERIFY_EXIT,
		verify_exit,
		sizeof(verify_exit) / sizeof(TCHAR)
		) == 0)
	{
		return (INT_PTR)FALSE;
	}

	int val = MessageBox(
		hWnd, 
		_T("Are you sure you want to exit?"), 
		_T("SourceMod Installer"), 
		MB_YESNO|MB_ICONQUESTION);

	if (val == 0 || val == IDYES)
	{
		UpdateGlobalPosition(hWnd);
		EndDialog(hWnd, NULL);
		return (INT_PTR)TRUE;
	}
	
	return (INT_PTR)FALSE;
}

size_t UTIL_GetFileSize(const TCHAR *file_path)
{
	HANDLE hFile;

	if ((hFile = CreateFile(file_path, 
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL)) 
		!= INVALID_HANDLE_VALUE)
	{
		LARGE_INTEGER size;

		if (GetFileSizeEx(hFile, &size))
		{
			CloseHandle(hFile);
			return (size_t)size.QuadPart;
		}

		CloseHandle(hFile);
	}

	return 0;
}

#if 0
size_t UTIL_GetFolderSize(const TCHAR *basepath)
{
	HANDLE hFind;
	WIN32_FIND_DATA fd;
	TCHAR search_path[MAX_PATH];
	size_t total = 0;

	UTIL_PathFormat(search_path,
		sizeof(search_path) / sizeof(TCHAR),
		_T("%s\\*.*"),
		basepath);

	if ((hFind = FindFirstFile(search_path, &fd)) == INVALID_HANDLE_VALUE)
	{
		return 0;
	}

	do
	{
		if (tstrcasecmp(fd.cFileName, _T(".")) == 0
			|| tstrcasecmp(fd.cFileName, _T("..")) == 0)
		{
			continue;
		}

		if ((fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY)
		{
			UTIL_PathFormat(search_path,
				sizeof(search_path) / sizeof(TCHAR),
				_T("%s\\%s"),
				basepath,
				fd.cFileName);
			total += UTIL_GetFolderSize(search_path);
		}
		else
		{
			UTIL_PathFormat(search_path,
				sizeof(search_path) / sizeof(TCHAR),
				_T("%s\\%s"),
				basepath,
				fd.cFileName);

			total += UTIL_GetFileSize(search_path);
		}
	} while (FindNextFile(hFind, &fd));

	FindClose(hFind);

	return total;
}
#endif
