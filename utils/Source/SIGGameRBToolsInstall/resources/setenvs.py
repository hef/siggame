import subprocess, os
from easygui import msgbox

# Test if user is running Vista
p = subprocess.Popen("setenv.exe -m DUMMY_ENV_VAR TEMP", shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
out = p.communicate()

# User is running Vista
if p.returncode == 2:
	msgbox(msg="Access denied, please run this batch file in administrator mode.", title="Error", ok_button="Ok")
	os._exit(1)

# User not using Vista, Delete the dummy environment variable and continue
p = subprocess.Popen("setenv.exe -m DUMMY_ENV_VAR -delete", shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)


#Get the PATH Environment variable
p = subprocess.Popen("setenv.exe -m path", shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
out = p.communicate()
	
#Set Msys PATH Environment Variable
if out[0].lower().find("c:\\msys\\1.0\\bin") < 0:
	print "Appending \";C:\\msys\\1.0\\bin\" to the PATH environment variable..."
	cmd = "setenv.exe -m path \"" + out[0][:-2] + ";C:\\msys\\1.0\\bin\""				# [:-2] is to get rid of the \r\n at the end
	subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

p = subprocess.Popen("setenv.exe -m path", shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
out = p.communicate()

#Set Python PATH Environment Variable	
if out[0].lower().find("c:\\python25") < 0:
	print "Appending \";C:\\Python25\" to the PATH environment variable..."
	cmd = 'setenv.exe -m path "' + out[0][:-2] + ';C:\\Python25"'
	subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

