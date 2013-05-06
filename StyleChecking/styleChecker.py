#! /usr/bin/python 
# -*- coding: utf-8 -*-

import os
import subprocess
import shutil
import glob
import sys
import re
from random import Random
from decimal import Decimal
import random

""" Version checking functions  
"""
def cppcheckVersion():
	# Write the version to a .version file 
	versionFile = "cppcheck.version"
	shellCmd = "cppcheck --version>" + versionFile
	subprocess.call(shellCmd, shell=True)
	
	# Read the version from the version file 
	version = open(versionFile, 'r')
	
	# Return the version 
	return version.read()


"""Structure that counts the number of issues in the code

:param error: used when bugs are found
:param warning: suggestions about defensive programming to prevent bugs
:param style: stylistic issues related to code cleanup (unused functions, redundant code, constness, and such)
:param performance: Suggestions for making the code faster. These suggestions are only based on common knowledge. It
is not certain you’ll get any measurable difference in speed by fixing these messages.
:param information: Informational messages about checking problems.
:param portability: portability warnings. 64-bit portability. code might work different on different compilers. etc.
:param log: Detailed log that contains all the information of the check

"""
class severityCounter:
	def __init__(self):
		self.error = 0
		self.warning = 0
		self.style = 0
		self.performance = 0 
		self.portability = 0
		self.information = 0 
		self.log = ""
		
		self.errorPenalty = -1
		self.warningPenalty = -0.25
		self.stylePenalty = -0.5
		self.performancePenalty = -0.25 
		self.portabilityPenalty = -0.25 

		
"""Severity checker
:param severtiy : Different issues with different severity levels 
:param svCtr : A counter that collects the issues reported  
""" 
def severtiyCheck(severtiy, svCtr):
	if (severtiy[2] == "error"):
		svCtr.log += "Error in " + str(severtiy[0]) + \
		" at line: " + str(severtiy[1]) + \
		", penalty " + str(svCtr.errorPenalty)  + " Marks"+ \
		"\n\t Type: " + str(severtiy[3]) + \
		", Message: " + str(severtiy[4])
		svCtr.error += 1
	elif (severtiy[2] == "warning"):
		svCtr.log += "Warning in " + str(severtiy[0]) + \
		" at line: " + str(severtiy[1]) + \
		", penalty " + str(svCtr.warningPenalty)  + " Marks"+ \
		"\n\t Type: " + str(severtiy[3]) + \
		", Message: " + str(severtiy[4])
		svCtr.warning += 1
	elif (severtiy[2] == "style"):
		svCtr.log += "Style issue in " + str(severtiy[0]) + \
		" at line: " + str(severtiy[1]) + \
		", penalty " + str(svCtr.stylePenalty)  + " Marks"+ \
		"\n\t Type: " + str(severtiy[3]) + \
		", Message: " + str(severtiy[4])
		svCtr.style += 1
	elif (severtiy[2] == "performance"):
		svCtr.log += "Performance issue in " + str(severtiy[0]) + \
		" at line: " + str(severtiy[1]) + \
		", penalty " + str(svCtr.performancePenalty)  + " Marks"+ \
		"\n\t Type: " + str(severtiy[3]) + \
		", Message: " + str(severtiy[4])
		svCtr.performance += 1
	elif (severtiy[2] == "portability"):
		svCtr.log += "Portability issue in " + str(severtiy[0]) + \
		" at line: " + str(severtiy[1]) + \
		", penalty " + str(svCtr.portabilityPenalty)  + " Marks"+ \
		"\n\t Type: " + str(severtiy[3]) + \
		", Message: " + str(severtiy[4])
		svCtr.portability += 1
	elif(severtiy[2] == "information "):
		pass
		svCtr.information += 1
	else:
		pass 

"""Print final report that concludes a summary and a detailed description of the issues 
:param svCtr: severity counter that appends all the issues in the source files   
"""
def printReport (svCtr):
	print("\n")
	print("********************")
	print("Static Check Summary")
	print("********************")
	print("Total number of errors is " + str(svCtr.error) + \
	", Grading (" + str(svCtr.errorPenalty * svCtr.error) +") Marks") 
	print("Total number of warnings is " + str(svCtr.warning) + \
	", Grading (" + str(svCtr.warningPenalty * svCtr.warning) +") Marks") 
	print("Total number of style issues is " + str(svCtr.style) + \
	", Grading (" + str(svCtr.stylePenalty * svCtr.style) +") Marks") 
	print("Total number of performance issues is " + str(svCtr.performance) + \
	", Grading (" + str(svCtr.performancePenalty * svCtr.performance) +") Marks") 
	print("Total number of portability issues is " + str(svCtr.portability) +\
	", Grading (" + str(svCtr.portabilityPenalty * svCtr.portability) +") Marks") 
	
	# Computing the total marks lost in the ckeck
	lostMarks = svCtr.errorPenalty * svCtr.error + \
				svCtr.warningPenalty * svCtr.warning + \
				svCtr.stylePenalty * svCtr.style + \
				svCtr.performancePenalty * svCtr.performance + \
				svCtr.portabilityPenalty * svCtr.portability 

	print("-------------------------------------------------------------")				
	print("Total number of lost marks is " + str(lostMarks))
	
	print("\n")
	print("*********************")
	print("Static Check Details")
	print("*********************")
	print(svCtr.log)
	
"""Print final report that concludes a summary and a detailed description of the 
issues to a file  
:param svCtr: severity counter that appends all the issues in the source files   
"""
def printReportToFile (svCtr, codePath, fileDirectory):
	fileName = codePath + "/" + fileDirectory + "/" + str(fileDirectory) + ".log"
	print("fileName ... ") 
	print(fileName) 
	fileHandle = open(fileName, 'w')
	fileHandle.write("\n")
	fileHandle.write("********************\n")
	fileHandle.write("Static Check Summary\n")
	fileHandle.write("********************\n")
	fileHandle.write("Total number of errors is " + str(svCtr.error) + \
	", Grading (" + str(svCtr.errorPenalty * svCtr.error) +") Marks\n") 
	fileHandle.write("Total number of warnings is " + str(svCtr.warning) + \
	", Grading (" + str(svCtr.warningPenalty * svCtr.warning) +") Marks\n") 
	fileHandle.write("Total number of style issues is " + str(svCtr.style) + \
	", Grading (" + str(svCtr.stylePenalty * svCtr.style) +") Marks\n") 
	fileHandle.write("Total number of performance issues is " + str(svCtr.performance) + \
	", Grading (" + str(svCtr.performancePenalty * svCtr.performance) +") Marks\n") 
	fileHandle.write("Total number of portability issues is " + str(svCtr.portability) +\
	", Grading (" + str(svCtr.portabilityPenalty * svCtr.portability) +") Marks\n") 
	
	# Computing the total marks lost in the ckeck
	lostMarks = svCtr.errorPenalty * svCtr.error + \
				svCtr.warningPenalty * svCtr.warning + \
				svCtr.stylePenalty * svCtr.style + \
				svCtr.performancePenalty * svCtr.performance + \
				svCtr.portabilityPenalty * svCtr.portability 

	fileHandle.write("-------------------------------------------------------------\n")				
	fileHandle.write("Total number of lost marks is " + str(lostMarks) + "\n")
	
	fileHandle.write("\n")
	fileHandle.write("*********************\n")
	fileHandle.write("Static Check Details\n")
	fileHandle.write("*********************\n")
	fileHandle.write(str(svCtr.log))
	fileHandle.close()


"""Print version checker after starting the execution  
"""
def printCheckerVersion():
	print("********************************************** \n")
	print("Static Checker for C++ based on " + str(cppcheckVersion()))
	print("**********************************************")
	
"""Main function 
"""
def runChecker(codePath, directory):
	
	# Print the "cppcheck" version 
	printCheckerVersion()
	
	# Basic command starts with running the executable  
	shellCommand = "cppcheck "
	
	# Enable all checks 
	enabled = "--enable=all "
	shellCommand += enabled
	
	# Inconclusive checks 
	shellCommand += "--inconclusive "
	
	# Reformat the output  
	template = " --template="
	templateArgs = "\"{file};{line};{severity};{id};{message}\""
	shellCommand += template + templateArgs
	
	# C++ files to check  
	checkFileorDir = codePath + "/" + directory
	shellCommand += " " + checkFileorDir
	 
	# Created log file  
	outputLog = "" + checkFileorDir + "/" + str(directory) + "_.log"
	shellCommand += " 2>" + outputLog

	# Execute the command 
	print("Bash Command : ")
	print("\t " + shellCommand + "\n")
	subprocess.call(shellCommand, shell=True)
	
	# Count the issues in the log files in their corresponding places 
	svCtr = severityCounter()
	sv_Log = ""
	
	# Parsing the log file 
	logFile = open(outputLog, 'r')
	for iLine in logFile:
		record = iLine.split(";")
		severtiyCheck(record, svCtr)
	
	# Print the final report that concludes the static check 
	printReportToFile(svCtr, codePath, directory)


if __name__ == '__main__':
	

# If the argument is 0 or null : use camera path, otherwise get a camera path 
    if (len(sys.argv) < 3):
        print("You have to provide a valid path to check the code ... ") 
        sys.exit(0) 
    elif(sys.argv[1] == "--path"): 
        codePath = sys.argv[2]
    
    dirList = os.listdir(codePath)
 
    for directory in dirList:
	print(directory) 
	
	# Run the Cpp Checker for a directory all together ...  
	runChecker(codePath, directory)


	
	
	
	

	

