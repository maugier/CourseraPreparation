#####################################################################
# Copyright © 2013,
# Marwan Abdellah: <abdellah.marwan@gmail.com>
#####################################################################

#########################################################
#! Minimum required CMake version
#########################################################
cmake_minimum_required(VERSION 2.6)

#########################################################
#! Project name
#########################################################
PROJECT(UnitTesting)

#########################################################
#! Find packages
#########################################################
# @ cppUnit
FIND_PACKAGE(PkgConfig)
PKG_CHECK_MODULES(CPPUNIT cppunit)

IF(CPPUNIT_FOUND)
  FIND_LIBRARY(CPPUNITLIBRARY cppunit
    HINTS $ENV{CPPUNIT_ROOT} ${CPPUNIT_ROOT}
    PATHS ${CPPUNIT_LIBRARY_DIRS}
    PATH_SUFFIXES lib)
  set(CPPUNIT_LIBRARIES ${CPPUNIT_LIBRARY})
ENDIF(CPPUNIT_FOUND)

# @ CPP Sources
SET(CPP_SOURCES     FractionTest.cpp
                    TestModules.cpp
                    Fraction.cpp)

# @ Include directories
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

#########################################################
#! Compiler Flags
#########################################################
SET(CMAKE_C_FLAGS " -fpermissive -fPIC -pthread -pipe -DLINUX -w")
SET(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS}")

#########################################################
# @ Linking
#########################################################
LINK_LIBRARIES(${CPPUNIT_LIBRARIES})

#########################################################
#! Compile Code
#########################################################
ADD_EXECUTABLE(unitTest ${CPP_SOURCES})



