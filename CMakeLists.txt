#This file can be used to build binder using preinstalled LLVM/Clang
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

include("cmake/Modules/HunterGate.cmake")
HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.23.297.tar.gz"
    SHA1 "3319fe6a3b08090df7df98dee75134d68e2ef5a3"
)

PROJECT(binder CXX C)
SET(VERSION 1.4.1)
option(STATIC "Statically compile Binder. See `documentation/install.rst` for more information." OFF)
set(CMAKE_VERBOSE_MAKEFILE ON)
#So far there are exceptions in config.cpp
set(LLVM_REQUIRES_EH ON)
set(USE_EXTERNAL_LLVM ON)
include("GNUInstallDirs")
set(LLVM_DIR_ORIG ${LLVM_DIR})
set(Clang_DIR_ORIG ${Clang_DIR})
# cmake version >= 3.19 includes all our modules
if(${CMAKE_VERSION} VERSION_LESS "3.19")
  set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules ${CMAKE_MODULE_PATH})
else()
  # set CMP0054 to NEW
  # https://cmake.org/cmake/help/latest/policy/CMP0054.html
  cmake_policy(SET CMP0054 NEW)
endif()
SET(CMAKE_MODULE_PATH_ORIG "${CMAKE_MODULE_PATH}")
set (CMAKE_MODULE_PATH "${LLVM_DIR};${Clang_DIR};${CMAKE_MODULE_PATH}")
option(BINDER_ENABLE_TEST      "Enables building of tests" ON)
option(BINDER_MOCK_TEST        "Mock running of binder on tests" OFF)
option(BINDER_USE_PYTHON_IN_TEST  "Try to import python modules during tests" ON)
if (NOT DEFINED BINDER_TEST_PYTHON_VERSIONS)
  set(BINDER_TEST_PYTHON_VERSIONS "0,2.7,3")
endif()
MESSAGE(STATUS  "binder: BINDER_ENABLE_TEST=${BINDER_ENABLE_TEST} with BINDER_TEST_PYTHON_VERSIONS=${BINDER_TEST_PYTHON_VERSIONS}. Note that version 0 can be used to check the generated sources agains the references.")
MESSAGE(STATUS  "binder: BINDER_USE_PYTHON_IN_TEST=${BINDER_USE_PYTHON_IN_TEST}")

hunter_add_package(LLVM)
hunter_add_package(Clang)

find_package(LLVM CONFIG REQUIRED)
find_package(Clang CONFIG REQUIRED)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})
llvm_map_components_to_libnames(llvm_libs support core)

include_directories(source)
add_subdirectory(source)
if (BINDER_ENABLE_TEST)
 if(${CMAKE_VERSION} VERSION_LESS "3.0.0")
   message("You are running cmake version ${CMAKE_VERSION}.")
   message("The testing suite will be disabled as it requires cmake 3.0.0 or higher.")
 else()
   ENABLE_TESTING()
   add_subdirectory(test)
 endif()
endif()
