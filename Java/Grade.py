#!/usr/bin/python
########################################################################
"""JavaCourseraGrader.py: 
This script is used to grade the submitted java files to the introductory 
and OOP Java courses running on Coursera for 2013/2014."""
__author__ = " Marwan Abdellah, Maxime, \
			   Jean-Cedric Chapplier, \
			   Lepitete Vinecnt, \
			   Jamila Sam"
__copyright__ = "Copyright 2013, EPFl"
__credits__ = ["Marwan Abdellah, \
				Maxime, \
				Jean-Cedric Chapplier, \
				Lepitete Vinecnt, \
				Jamila Sam"]
__license__ = "GPL"
__version__ = "1.0.0"
__maintainer__ = "Marwan Abdellah"
__email__ = "marwan.abdellah@epfl.ch"
__status__ = "Testing"
########################################################################

""" ALGORITHM (For every iteration or file)
*) Erase all the generated files from a previous compilation trial  
*) Copy all the submitted files to the source "src" directory 
*) Compile all the submitted files 
*) If the compilation fails, grade = 0, report the failure and exit
*) If the compilation succeeded, Compile the test cases 
*) Run the test cases and dump the individual report
*) Grade the resulting reports
*) Construct the final report and the grade 
*) Submit back the result and the final report.      
"""
import os
import subprocess
 
########################################################################
""" NOTES:
* This code is based on junit4 
"""
JAVA_COMPILER = "javac"
JAVA_RUNNER = "java"
JUNIT_PATH = "/usr/share/java/junit4.jar"
JUNIT_CORE = "org.junit.runner.JUnitCore"
#SUBMITED_SOURCE_DIR = "/home/abdellah/Desktop/src/submitted"
#UNIT_TESTS_DIR = "/home/abdellah/Desktop/src/tests"
SUBMITED_SOURCE_DIR = "/home/max/mooc-prog/CourseraPreparation/Java/src/submitted"
UNIT_TESTS_DIR = "/home/max/mooc-prog/CourseraPreparation/Java/src/tests"
########################################################################

########################################################################
# Assignment-specific Classes 
# note that the class name MUST be the same name of the containg JAVA, 
# file, otherwise the file will not compile 
# These classes should be changed for each assignment     
# The corresponding Java file = $FILE_NAME + ".java"
# The corresponding JUnit file = $FILE_NAME + "Test.java"
# The corresponding Report file = $FILENAME + ".report" 
__classNames = ["Add",
				"Subtract",
				"Multiply",
				"Divide"]
########################################################################

#######################################################################
""" Grading policy  """        
# For every test give it 2 points 
__testPoint = 2

""" Final grade to be reported  """
__finalGrade = 0  

# Final report the summarizes every thing in it 
__finalReportString = ""        
########################################################################

# __debug
__debugGlob = True

"""
! This struct summarizes the number of passed and failed tests 
"""
class _reportTest_:
	def __init__(self):
		# Report name 
		self.__name = "NO_NAME_SO_FAR"
		# TB incremented once a test passes 
		self.__pass = 0
		# TB incremented once a test fails 
		self.__fail = 0
		# Compilation state 
		self.__compiled = 0
		# The failing tests or compilation
		self.__message = ""
		# Final grade for every individual report 
		self.__grade = 0
		
"""
! Adds the current directory to the CLASSPATH
  This step is mandatory for successfull test running   
"""
def _addCurrentPathToCLASSPATH_(__exportPath):
	
	# __debug 
	global __debugGlob 
	__debugLocl = False 
	
	# Form the shell command 
	__shellCommand = "export CLASSPATH=$CLASSPATH:" + __exportPath 
	
	if (__debugGlob or __debugLocl):
		print (__shellCommand) 
		
	# Run the shell command 
	process = subprocess.Popen(__shellCommand, shell=True, stdout=subprocess.PIPE)
	process.wait()
	return process.returncode
	
# Check extension case 
def _checkExtensionCase_():
	printf("")
 
"""
! Compiles a single java file and returns either sucess or fail 
"""
def _compileFile_(__fileName, __report):
	
	# __debug 
	global __debugGlob 
	__debugLocl = False 
	
	if (__debugGlob or __debugLocl):
		print ("Compiling file " + str(__fileName))
		
	# Check for the existance of the file 
	
	
	# Form the shell string 
	__shellCommand = JAVA_COMPILER + " " + __fileName + ".java"
	if (__debugGlob or __debugLocl):
		print ("\t " + __shellCommand) 
	
	# Compile the file 
	__compilationResultFile = open(__fileName + ".compile", 'w')
	process = subprocess.Popen(__shellCommand, shell=True, stderr=__compilationResultFile, stdout=__compilationResultFile)
	process.wait()
	
	# Closing the resulting file from the compilation step 
	__compilationResultFile.close()
	
	# Open the file once more but in read only mode 
	__compilationResultFile = open(__fileName + ".compile", 'r')
	
	# Read the FILE.compile to get any existing errors 
	__compileERROR = __compilationResultFile.read()
	
	# Close the file 
	__compilationResultFile.close()
	
	if (process.returncode == 0): 
		__report.__compiled = 1
		if (__debugGlob or __debugLocl): 
			print("\t " + __fileName + " has been compiled successfully")
	else:
		__report.__compiled = 0
		__report.__message = str(__compileERROR)
		if (__debugGlob or __debugLocl): 
			print("\t " + __fileName + " did NOT compile")
		
	return process.returncode

"""
! Compiles a single java "JUnit" test file and returns either sucess or fail 
"""
def _compileTest_(__fileName, __report):
	
	# __debug 
	global __debugGlob 
	__debugLocl = False
	
	if (__debugGlob or __debugLocl):
		print ("Compiling file " + str(__fileName))
	
	# Check if the submitted file compiles or not 
	if (__report.__compiled == 0):
		if (__debugGlob or __debugLocl): 
			print("The submitted file did NOT compile")
		return 
	
	# Appending the Test to the file name $FILE_NAME${Test}
	__fileName += "Test" 
		
	# Form the shell string 
	__shellCommand = JAVA_COMPILER + " " + " -cp .:" + JUNIT_PATH + " " 
	__shellCommand += __fileName + ".java"
	if (__debugGlob or __debugLocl):
		print ("\t " + __shellCommand) 
	
	# Compile the test file 
	process = subprocess.Popen(__shellCommand, shell=True, stdout=subprocess.PIPE)
	process.wait()
	
	if (process.returncode == 0): 
		if (__debugGlob or __debugLocl): 
			print("\t " + __fileName + " has been compiled successfully")
	else:
		if (__debugGlob or __debugLocl): 
			print("\t " + __fileName + " did NOT compile")
			
	return process.returncode

"""
! Run a JUnit test suite  
"""
def _runTest_(__exeFileName, __report):

	# __debug 
	global __debugGlob
	__debugLocl = False 
	
	if (__debugGlob or __debugLocl):
		print ("Running test " + str(__exeFileName))
	
	# Check if the submitted file compiles or not 
	if (__report.__compiled == 0):
		if (__debugGlob or __debugLocl): 
			print("The submitted file did NOT compile, the test will NOT run")
		return 
	
	# From the shell command 
	__shellCommand = JAVA_RUNNER + " -cp .:" + JUNIT_PATH + " " 
	__shellCommand += JUNIT_CORE + " " + __exeFileName + "Test"
	
	# Write the test result in the report file 
	__reportFile = __exeFileName + ".report"
	__fileHandle = open(__reportFile, "w")
	
	if (__debugGlob or __debugLocl):
		print ("\t " + __shellCommand) 
	
	# Run the tests and dump the reports  
	process = subprocess.Popen(__shellCommand, shell=True, stdout=__fileHandle)
	process.wait()
	
	# Close the report file 
	__fileHandle.close()

"""
Parses the generated report to get the error are the final grades 
"""
def _parseTestReport_(__reportTest, __report):
	
	# __debug 
	global __debugGlob
	__debugLocl = False  
	
	if (__debugGlob or __debugLocl):
		print ("Parsing the TEST REPORT: " + __reportTest)
		
	# A report that reflects the status of the test cases in the java file 
	__report.__name = __reportTest
	
	if (__report.__compiled == 0):
		return 
	
	# Open the resulting report from the test to parse it 
	__reportTestFile = __reportTest + ".report"
	__fileHandle = open(__reportTestFile,'r')
	
	# Checks whether the test passes or fails for the first loop 
	# to have a cascading decision in the second loop 
	__testPassed = True
	
	# Parse every line in the file to fetch the required strings 
	for __line in __fileHandle:
		# All the test cases are successfully passed 
		if ("OK" in __line):
			if (__debugGlob or __debugLocl):
				print ("\t All the test cases have been successfully passed")
			__testPassed = True
			
			# Get the total number of tests from __line 
			__numTestPasses = ''.join(filter(str.isdigit, __line))
			if (__debugGlob or __debugLocl):
				print ("\t " + str(__numTestPasses) + " test cases have been successfully passed") 
			
			# Report the success of the test cases 
			__report.__pass = __numTestPasses; 
			__report.__fail = 0
			__report.__message = "All the test are passed successfully"

		# Some test cases fail 
		# Normally, JUnit reports "There was 1 failure" or "There was N failures"
		# A simple check can be done by matching the "there" string as it 
		# is not repeated anywhere else in the report  
		elif ("There" in __line):
			if (__debugGlob or __debugLocl):
				print("\t Some test case fails")	
			__testPassed = False
	
	# Closing the file 
	__fileHandle.close()	
	
	# The total number of failing tests 
	# This will be used later to find the failing tests 
	__numFailingTests = 0
		
	# All tests were passed 
	if (__testPassed):
		return __report
	# Some tests fail 
	else:
		# open the resulting report once more  
		__fileHandle = open(__reportTestFile,'r')
		for __line in __fileHandle:
				# Normally, JUnit reports "There was 1 failure" or "There was N failures"
				# A simple check can be done by matching the "there" string as it 
				# is not repeated anywhere else in the report
				# This gets the number of failing tests  
			if ("There" in __line):
				# Split the string into array for fetching the first string 
				__splitLine = __line.split(" ")
				__numFailingTests = __splitLine[2]
				if (__debugGlob or __debugLocl):
					print ("\t " + str(__numFailingTests) + " failing test(s)")
			elif ("Test" in __line and "run:" in __line and "Failures:" in __line): 
				# Split to get the total number of tests and the failing ones 
				__splitLine = __line.split(",")
				
				__totalTests = ''.join(filter(str.isdigit, __splitLine[0]))
				__failingTests = ''.join(filter(str.isdigit, __splitLine[1]))
				
				if (__debugGlob or __debugLocl):
					print ("\t " + "Total/Failing: " + str(int(__totalTests)) + "/" + str(int(__failingTests)))
				
				# Add them to the report 
				__report.__pass = int(__totalTests) - int(__failingTests)
				__report.__fail = int(__failingTests)
				
		# Close the file and break 
		__fileHandle.close()	
	
	# Failing test iteration 
	__failItr = 1
	
	# Open the file once more to identify the functions of the failing tests 
	__fileHandle = open(__reportTestFile,'r')
	
	# Failing Tests 
	__failTestMessage = ""
	for __line in __fileHandle:
		# Form fail string 
		# The form in the report file is 1) , 2) , .. N) 
		__failString = str(__failItr) + str(")")
		
		# Split the string to get the first sub string that matches 
		# the test number 
		__splitLine = __line.split(" ")
		if (__failString == __splitLine[0]):
			if (__debugGlob or __debugLocl):
				print("\t This test FAILS: " + str(__splitLine[1]))
			
			# Add the failing test to the report 
			__failTestMessage += "FAILURE : " + str(__splitLine[1])
			 
			# Increment the iterator to get the next failing test 
			__failItr = __failItr + 1
	 
	 # Close the report file 
	__fileHandle.close() 
	
	# Append the failing tests to the report file 
	__report.__message = __failTestMessage

"""
Append the individual report to the final report
"""
def _appendToFinalReport(__report):
	# Final report string 
	global __finalReportString 
	
	__finalReportString += "************************************************************\n"
	__finalReportString += "Submitted File: " + __report.__name + "\n"
	if (__report.__compiled == 1):
		__finalReportString += "\t " + "Compilation Status : COMPILED \n"
		__finalReportString += "\t " + "Number of Tests Passed/Failed " 
		__finalReportString += str(__report.__pass) + "/" + str(__report.__fail) + "\n"
		__finalReportString += "\t Failed Tests : " + __report.__message + "\n"
		__finalReportString += "\t Total Number of Obtained Points : "   + str(__report.__grade) + "\n"
	else: 
		__finalReportString += "\t " + "Compilation Status : DID NOT COMPILED \n"
		__finalReportString += "\t Problems : "   + str(__report.__message) + "\n"
		__finalReportString += "\t Total Number of Obtained Points : "   + str(__report.__grade) + "\n"
	__finalReportString += "************************************************************\n"
	

"""
Grades an individual rport 
"""
def _gradeReport_(__report):
	
	# __debug 
	global __debugGlob
	__debugLocl = False  
	
	# Gradeing points  
	global __testPoint
	
	if (__debugGlob or __debugLocl):
		if (__report.__compiled == 1):
			print ("Grading TEST REPORT: " + __report.__name)	
			print ("\t " + str(__report.__pass) + " test(s) PASS")
			print ("\t " + str(__report.__fail) + " test(s) FAIL")
			print ("\t NOTES: " + str(__report.__message))
		else:
			print ("\t NOTES: DIDN'T COMPILE >> " + str(__report.__message))
	
	if (__report.__compiled == 1):	
		__report.__grade = int (__report.__pass) * __testPoint 
	else:
		__report.__grade = 0
		
	# Append the data to the final report to be sent to the student 
	_appendToFinalReport(__report)
			
"""
! Copies the submitted files to the source directories to have them 
integrated in the JAVA environment  
"""
def _copyJavaFiles_(__srcDir, __destDir):
	
	# __debug 
	global __debugGlob 
	__debugLocl = False 
	
	if (__debugGlob or __debugLocl):
		print ("Copying the submitted files ")
		
		# Form the shell string 
	__shellCommand = "cp -r " + __srcDir + "/* " + __destDir + "/."
	if (__debugGlob or __debugLocl):
		print ("\t " + __shellCommand) 
	
	# Copy the file  
	process = subprocess.Popen(__shellCommand, shell=True, stdout=subprocess.PIPE)
	process.wait()	

"""
Copies the JUnit test files to the destination directories 
"""	
def _copyJUnitFiles_(__srcDir, __destDir):
	
	# __debug 
	global __debugGlob 
	__debugLocl = False 
	
	if (__debugGlob or __debugLocl):
		print ("Copying the JUnit test files ")
		
		# Form the shell string 
	__shellCommand = "cp -r " + __srcDir + "/* " + __destDir + "/."
	if (__debugGlob or __debugLocl):
		print ("\t " + __shellCommand) 
	
	# Copy the file  
	process = subprocess.Popen(__shellCommand, shell=True, stdout=subprocess.PIPE)
	process.wait()	

""" 
Runs the grader 
"""
def _runJavaGrader():
	
	# Global _debug 
	global __debugGlob
	
	# Final Reults
	global __finalGrade
	
	if (__debugGlob): 
		print ("The current directory is " + os.getcwd())
	
	_copyJavaFiles_(SUBMITED_SOURCE_DIR, os.getcwd())
	_copyJUnitFiles_(UNIT_TESTS_DIR, os.getcwd())
	
	# Add the source path to the CLASSPATH
	_addCurrentPathToCLASSPATH_(os.getcwd())
	
	# Compile a list of reports to track the results of each step 
	__reportList = []
	for __iClass in __classNames:
		__report = _reportTest_()
		__report.__name = str(__iClass)
		__reportList.append(__report)
	
	# Compiling the source file  
	for __iFile , __iReport in zip(__classNames, __reportList):
		_compileFile_(__iFile, __iReport)
	
	# Compiling the test files 
	for __iTest, __iReport in zip(__classNames, __reportList):
		_compileTest_(__iTest, __iReport)
	
	# Running the tests  	
	for __iTest, __iReport in zip(__classNames, __reportList):
		_runTest_(__iTest, __iReport)
	
	# Grading 
	__finalGrade = 0
	for __iResult, __iReport in zip(__classNames, __reportList):
		_parseTestReport_(__iResult, __iReport)
		_gradeReport_(__iReport)
		__finalGrade += __iReport.__grade

"""
Gets the final results 
"""		
def _getFinalResult():
	global __finalGrade
	return  __finalGrade
	
"""
Gets the final report that should be sent to the students 
"""
def _getFinalReport(): 
	global __finalReportString
	return __finalReportString

"""
Write final report to disk 
"""
def _writeFinalReport():
	global __finalReportString
	
	# Open the reportfile 
	__fileHandle = open("Report.coursera", 'w')
	
	# Dump thr report to the file 
	__fileHandle.write(__finalReportString)
	
	# Close the file stream 
	__fileHandle.close()

def java_unit_grader(sub):
    global SUBMITED_SOURCE_DIR
    global UNIT_TESTS_DIR
   
    SUBMITED_SOURCE_DIR = sub.workdir
    UNIT_TESTS_DIR = "{0}/javatests".format(sub.datadir)
    
    os.chdir(SUBMITED_SOURCE_DIR)
    
    _runJavaGrader()

    sub.feedback(_getFinalReport())
    sub.points(_getFinalResult())
		

if __name__ == '__main__':
########################################################################
# Run the Java Coursera Grader 		
########################################################################
    _runJavaGrader()

########################################################################
# Print the final report to the console  
########################################################################
    print (__finalReportString)
    print ("The final grade is " + str(__finalGrade))
