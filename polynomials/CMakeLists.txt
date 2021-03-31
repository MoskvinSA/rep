cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME polynomials)
project(${PROJECT_NAME})

set(polynomialslib polynomialslib)
set(sample sample) 

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/polynomialslib)

add_subdirectory(polynomialslib)
add_subdirectory(sample)
add_subdirectory(gtest)
add_subdirectory(test)
