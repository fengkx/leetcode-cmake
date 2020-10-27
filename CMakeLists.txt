cmake_minimum_required(VERSION 3.0.0)
project(leetcode VERSION 0.1.0)

enable_testing()
find_package(Threads REQUIRED)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})


include_directories(${CMAKE_SOURCE_DIR}/include)

MACRO(SUBDIRLIST result curdir)
     FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
     SET(dirlist "")
     FOREACH(child ${children})
       IF(IS_DIRECTORY ${curdir}/${child})
         LIST(APPEND dirlist ${child})
       ENDIF()
     ENDFOREACH()
     SET(${result} ${dirlist})
ENDMACRO()

SUBDIRLIST(problems ${CMAKE_CURRENT_SOURCE_DIR}/problems)

add_subdirectory(include)
foreach(problem ${problems})
add_subdirectory(problems/${problem})
endforeach()