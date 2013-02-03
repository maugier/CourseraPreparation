#####################################################################
# Copyright © 2011-2012,
# Marwan Abdellah: <abdellah.marwan@gmail.com>
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation.

# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.

# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
# MA 02110-1301, USA.
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

MESSAGE(${CPPUNIT_LIBRARIES})
ELSE()
  MESSAGE("CPP UNIT NOT-FOUND")
ENDIF(CPPUNIT_FOUND)

# @ CPP Sources
SET(CPP_SOURCES     FractionTest.cpp
                    TestModules.cpp
                    Fraction.cpp
)



# @ Include directories
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

#########################################################
#! Compiler Flags
#########################################################
SET(CMAKE_C_FLAGS " -fpermissive -fPIC -pthread -pipe -DLINUX -D_BOOL -DREQUIRE_IOSTREAM -Wno-deprecated -fno-gnu-keywords -w")
SET(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS}")

#########################################################
# @ Linking
#########################################################
LINK_LIBRARIES("/usr/lib/libcppunit.so")

#########################################################
#! Compile Code
#########################################################
ADD_EXECUTABLE(unitTest ${CPP_SOURCES})



