import subprocess

#Get the PATH Environment variable
p = subprocess.Popen("setenv.exe -m path", shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
out = p.communicate()

#Set Perl PATH Environment Variable
if out[0].lower().find("c:\\msys\\1.0\\bin") < 0:
	print "Appending \";C:\\msys\\1.0\\bin\" to the PATH environment variable..."
	cmd = "setenv.exe -m path \"" + out[0][:-2] + ";C:\\msys\\1.0\\bin\""				# [:-2] is to get rid of the \r\n at the end
	subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)