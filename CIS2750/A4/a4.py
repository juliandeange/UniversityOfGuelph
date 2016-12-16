#!/usr/bin/python3

import os, sys


filename = "./toPython"
sendBack = "./toC"
os.mkfifo(filename)
os.mkfifo(sendBack)

pipe = open(filename, "r")
pipeBack = open(sendBack, "w")

count = 0
while True:
	count = count + 1
	line = pipe.readline()
	line = line.rstrip()
	if not line: break

	if count == 1:
		IF = "files/" + (line) + ".info"
		line = ("<HTML>\n<HEAD>\n<TITLE>") + (line) + ("</TITLE>\n</HEAD>\n<BODY>") 

	try:
		infoFile = open(IF, "r")
	except FileNotFoundError:
		pipeBack.write(line)
		continue

	while True:
		content = infoFile.readline()
		content = content.rstrip()
		if not content: break
		a = content.split(" ", 1)
		# a[0] = B I or U
		# a[1] = String to be changed
		if (a[1] in line):
			if (a[0] is "B"):
				newStr = "<B>"+a[1]+"</B>"
				line = line.replace(a[1], newStr)
			elif (a[0] is "I"):
				newStr = "<I>"+a[1]+"</I>"
				line = line.replace(a[1], newStr)
			elif (a[0] is "U"):
				newStr = "<U>"+a[1]+"</U>"
				line = line.replace(a[1], newStr)

	pipeBack.write(line)
pipeBack.write("\n</BODY>\n</HTML>")
#os.write(pipeBack, "</BODY>\n</HTML>")

os.remove(filename)

