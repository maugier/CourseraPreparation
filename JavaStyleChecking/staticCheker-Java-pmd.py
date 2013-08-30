#! /usr/bin/python 
# -*- coding: utf-8 -*-

########################################################################
"""staticChecker-Java-pmd.py: 
This script is used to grade the submitted java files to the introductory 
and OOP Java courses running on Coursera for 2013/2014."""
__author__ = " Marwan Abdellah, Maxime Augier, \
			   Jean-Cedric Chapplier, \
			   Lepitete Vinecnt, \
			   Jamila Sam"
__copyright__ = "Copyright 2013, EPFL"
__credits__ = ["Marwan Abdellah, \
				Maxime Augier, \
				Jean-Cedric Chapplier, \
				Lepitete Vinecnt, \
				Jamila Sam"]
__license__ = "GPL"
__version__ = "1.0.0"
__maintainer__ = "Marwan Abdellah"
__email__ = "marwan.abdellah@epfl.ch"
__status__ = "Testing"
####################################################################

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
* The script doesn't work if the compilation stage is failed. 
* The static checker should be running in a separte directory to avoid 
  un wanted warnings from the testc cases.  
* The grade must be scaled later on according to the assignment 
* The script runs in the following way 
	/bin/run.sh pmd 	# Run the script 
	-d <file.java> 		# Supply a file to be checked 
	-f text			 	# Text format for the output file 
	-R <rule.xml> 		# Specify a certain rule 
	-version 1.7 		# PMD version 
	-language java 		# Specificy the langauge 
* We have the following checks to choose from "later"
		android.xml
		basic.xml
		braces.xml
		clone.xml
		codesize.xml
		comments.xml
		controversial.xml
		coupling.xml
		design.xml
		empty.xml
		finalizers.xml
		imports.xml
		j2ee.xml
		javabeans.xml
		junit.xml
		logging-jakarta-commons.xml
		logging-java.xml
		migrating_to_13.xml
		migrating_to_14.xml
		migrating_to_15.xml
		migrating_to_junit4.xml
		migrating.xml
		naming.xml
		optimizations.xml
		rulesets.properties
		strictexception.xml
		strings.xml
		sunsecure.xml
		typeresolution.xml
		unnecessary.xml
		unusedcode.xml
"""

"""
! Runs the static checker and dumps the report file to be parsed 
for grading. 
"""
def runStaticChecker(srcFile, reportFilePath, pmdScript, pmdRule):

	# Command for running the static checker 
	shellCommand = pmdScript 
	
	# Indicate the checker 
	shellCommand += " pmd -d "
	
	# File to be checked 
	shellCommand += srcFile
	 
	# For command line user interface 
	shellCommand += " -f text" 
	
	# Rule set 
	shellCommand += " -R " + pmdRule
	
	# Version 
	shellCommand += " -version 1.7"
	
	# Language 
	shellCommand += " -language java"
	
	# Output report file that contains all the warnings messages 
	shellCommand += ">>" + reportFilePath 
	
	print "Bash Command : \t " + shellCommand + "\n"
	subprocess.call(shellCommand, shell=True)

"""
! Parses the report file and return the total number of lost points 
  and the messages  
"""
def parseReportFile(reportFilePath):
	
	# Report data in details 
	reportData = ""
		
	# Open the report file 
	reportFile = open(reportFilePath, 'r')
	
	# Initial number of warning 
	numWarn = 0

	# Read every single line in the file and parse it. 
	for iLine in reportFile:
		
		# Check for the logged warning messages.  
		if (":" in iLine):
			record = iLine.split(":")
			
			# The record always has 3 parts, else, there is some problem.
			if (len(record) == 3):
				
				# If the record contains always 2 parts, then that's a warning 
				# report it and increment the number of warnings.
				numWarn = numWarn + 1
				reportData += "@Line:" + str(record[1]) + ": " + record[2] + "\n"
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

"""
# TODOs 
# Define the source directory and the files to be ckeched. 
# Define the path to the PMD "run.sh" script (normal under the bin directory).
# Define the path to the checking rules that the grader will be consider. 
"""
def main():
	# Java source file to be checked "will be passed to the main function. 
	# If more than one file needs to be checked, then you just pass the parent directory
	# that contains all the files.  
	srcFile = "/home/abdellah/Desktop/Coursera/CourseraPreparation/JavaStyleChecking/code/src/sample.java" 

	# The report file that contains all the warning messages. 
	# For the moment, I just put it in the curent directory, ans I append to it 
	# the new messages every time I just run a new rule check. 
	# We need to clean the file at the first run sp that we can append the 
	# different messages from the different rules. 
	reportFilePath = os.getcwd() + "/styleChecker.report"
	subprocess.call("rm " + reportFilePath, shell=True)
	
	"""
	PMD stuff, should be passed to the @main function.  
	"""
	# PMD script  
	pmdScript = "/home/abdellah/Desktop/Coursera/CourseraPreparation/JavaStyleChecking/pmd/pmd-src-5.0.4/bin/run.sh"
	
	# PMD rule 
	pmdRuleList =  ["android.xml", 
					"basic.xml",
					"braces.xml",
					"clone.xml",
					"codesize.xml",
					"comments.xml",
					"controversial.xml",
					"design.xml",
					"empty.xml",
					"finalizers.xml",
					"imports.xml",
					"j2ee.xml",
					"javabeans.xml",
					"junit.xml",
					"logging-jakarta-commons.xml",
					"logging-java.xml",
					"migrating_to_13.xml",
					"migrating_to_14.xml",
					"migrating_to_15.xml",
					"migrating_to_junit4.xml",
					"migrating.xml",
					"naming.xml",
					"optimizations.xml",
					"rulesets.properties",
					"strictexception.xml",
					"strings.xml",
					"sunsecure.xml",
					"typeresolution.xml",
					"unnecessary.xml",
					"unusedcode.xml"]
	
	
	pmdRulePath = "/home/abdellah/Desktop/Coursera/CourseraPreparation/JavaStyleChecking/pmd/pmd-bin-5.0.4/rulesets/java/"
	
	# Check the selected rules in the list "CUSTOMIZABLE"  
	for rule in pmdRuleList:
		pmdRule = pmdRulePath + rule 
		
		# Run the static checker with the specified rule and dump the result to the report file  
		runStaticChecker(srcFile, reportFilePath, pmdScript, pmdRule)
	
	# Parse the generated report file.  
	warningData, numWarnings = parseReportFile(reportFilePath)
	
	# Display the lost points and the final message that will be sent 
	# back to the student indicating the total number of lost marks. 
	# This message is just for testing purpose 
	print("Total number of lost points is " + str(getLostPoints(numWarnings)))
	print("The final messges will be : " )
	print (warningData)

# Run the main function. 
# You have to pass to the main function where we keep the bin and the src
# directories of PMD. You will find the version used to develop this grader 
# uploaded to the course repository. 
main()
	
	
	
	
	
	




