cmake_minimum_required(VERSION 3.28)
project("set-calc")

include_directories("${PROJECT_SOURCE_DIR}/headers/")
link_directories("${PROJECT_SOURCE_DIR}/build/libs/")

set(CMAKE_CXX_STANDARD             20)
set(CMAKE_EXPORT_COMPILE_COMMANDS  true)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/output")
set(EXECUTABLE_OUTPUT_PATH         "${PROJECT_SOURCE_DIR}/output")

add_library("get-mode-number"  STATIC "src/getModeNumber.cpp")
add_library("init-vec-array"   STATIC "src/initVecArray.cpp")
add_library("set-control"      STATIC "src/setControl.cpp")
add_library("num-math"         STATIC "src/numMath.cpp")
target_link_libraries("num-math" "get-mode-number")
add_executable("set-calc" "src/main.cpp")

target_link_libraries("set-calc" "init-vec-array" "set-control" "num-math")

