import subprocess, sys
from easygui import passwordbox, msgbox

if len(sys.argv) != 5:
	sys.exit()

password = passwordbox(msg="Enter your ACM password:", title="Password", default="")
if password == "":
	password = passwordbox(msg="(Null Password Entered.  Try Again) Enter your ReviewBoard password:", title="Password", default="")
	if password == "":
		sys.exit()

if password == None:
	sys.exit()

if sys.argv[4] == "default":
	msgbox(msg="The default changelist cannot be used for a review.  Please move files into a named changelist.", title="Error", ok_button="Ok")
	sys.exit()
	
#C:\Python25\Scripts\post-review -d -o --server=http://chi-revboard-01 --p4-port=$p --username=$u --password=PASSWORD --p4-client=$c %c
cmd = ""
cmd = cmd + "C:\Python25\python.exe C:\Python25\Scripts\post-review -d -o --server=http://acm.cs.uic.edu/siggame/reviewboard" + " "
cmd = cmd + "--p4-port=" + sys.argv[1] + " "
cmd = cmd + "--username=" + sys.argv[2] + " "
cmd = cmd + "--password=" + password + " "
cmd = cmd + "--p4-client=" + sys.argv[3] + " "
cmd = cmd + sys.argv[4]

p = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
out = p.communicate()

out = out[0]

#http://code.google.com/p/reviewboard/wiki/ReviewBoardAPI
if out.lower().find("code 101") >=0:
	msgbox(msg="You don't have permission for this action.", title="Error", ok_button="Ok")
	sys.exit()
	
if out.lower().find("username or password was not correct") >=0:
	msgbox(msg="The username and password provided were incorrect.", title="Error", ok_button="Ok")
	sys.exit()

if out.lower().find("code 206") >=0:
	msgbox(msg="Perforce Server Unknown.  Contact ReviewBoard administrator (tsakkos@midway.com) and let them know.", title="Error", ok_button="Ok")
	sys.exit()
	
if out.lower().find("code 207") >=0:
	msgbox(msg="File that should exist doesn't exist in repository.", title="Error", ok_button="Ok")
	sys.exit()

if out.lower().find("code 208") >=0:
	msgbox(msg="User does not exist.  Please contact ReviewBoard administrator (tsakkos@midway.com).", title="Error", ok_button="Ok")
	sys.exit()

if out.lower().find("code 212") >=0:
	msgbox(msg="Cannot do this action with an empty changelist.", title="Error", ok_button="Ok")
	sys.exit()
	
if out.lower().find("http error 500: internal server error") >= 0:
	msgbox(msg="Interal Server Error", title="Error", ok_button="Ok")
	sys.exit()

print "Success."
