#ifndef _INCLUDE_INSTALLER_H_
#define _INCLUDE_INSTALLER_H_

#include "platform_headers.h"
#include "Resource.h"

void UpdateGlobalPosition(HWND hWnd);
void SetToGlobalPosition(HWND hWnd);

typedef void *(*NEXT_DIALOG)(HWND);

extern HINSTANCE g_hInstance;

#endif //_INCLUDE_INSTALLER_H_
