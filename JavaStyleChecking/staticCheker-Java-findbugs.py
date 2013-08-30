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

"""
NOTES: 
* The static checker shoud be running on the .java files after being compiled. 
* The static checker should be running in a separte directory to avoid 
  un wanted warnings from the testc cases.  
"""

"""
! Runs the static checker and dumps the report file to be parsed 
for grading. 
"""
def runStaticChecker(projDir, reportFilePath, FIND_BUGS_BIN):
	
	# Command for running the static checker 
	shellCommand = FIND_BUGS_BIN 
	
	# Command line arguments 
	# For command line user interface 
	shellCommand += " -textui " 
	
	# Output report file that contains all the warnings messages 
	shellCommand += " -outputFile " + reportFilePath 
	
	# Project directory 
	shellCommand += projDir
	
	print "Bash Command : \t " + shellCommand + "\n"
	subprocess.call(shellCommand, shell=True)

def parseReportFile(reportFilePath):
	
	# Report data in details 
	reportData = ""
		
	# Open the report file 
	reportFile = open(reportFilePath, 'r')
	
	# Number of warning 
	numWarn = 0

	# Read every single line in the file 
	for iLine in reportFile:
		
		# Check for the warning messages 
		if (": " in iLine):
			record = iLine.split(": ")
			
			# The record always has 2 parts 
			if (len(record) == 2):
				
				# If the record contains always 2 parts, then that's a warning 
				numWarn = numWarn + 1
				
				reportData += record[1] + "\n"
	return (reportData, numWarn)
		
	
"""
! Returns the total number of lost points from the static checker 
"""
def getLostPoints(numWarnings):
	
	# Penalty for a single warning 
	warningPenalty = -1
	
	# Total lost points 
	lostPoints = numWarnings * warningPenalty 
	return lostPoints 



def main():
	
	# Define the project directory (containg the source code and the compilation units) 
	projDir = " Java/dst/" 
	
	# Report file 
	reportFilePath = os.getcwd() + "report.txt"
	
	# FindBugs executable 
	FIND_BUGS = "findbugs-2.0.2/bin/findbugs"
	
	# Run the static checker 
	runStaticChecker(projDir, reportFilePath, FIND_BUGS)
	
	# Parse the generated report file  
	
	warningData, numWarnings = parseReportFile(reportFilePath)
	
	# Display the lost points and the final message that will be sent 
	# back to the student indicating the total number of lost marks. 
	 
	print("Total number of loist points is " + str(getLostPoints(numWarnings)))
	print("The warning messges : " )
	print (warningData)
	
main()
	
	
	
	
	
	




