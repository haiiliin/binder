cmake_minimum_required(VERSION 3.4.3)
project(binder VERSION 1.4.1 LANGUAGES CXX C)

set(LLVM_ENABLE_EH ON)
set(LLVM_ENABLE_RTTI ON)
set(LLVM_ENABLE_PROJECTS "clang")
set(BINDER_BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/binder/bin)

add_subdirectory(llvm-project/llvm)
