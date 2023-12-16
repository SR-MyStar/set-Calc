# Copyright (c) 2023 Star. All Rights Reserved.
#
# This file is part of set-calc.
#
# set-calc is free software: you can redistribute it and/or modify it under the
# terms of the GNU General Public License as published by the Free Software
# Foundation, either version 3 of the License, or (at your option) any later
# version.
#
# set-calc is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
# A PARTICULAR PURPOSE. See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along with
# set-calc. If not, see <https://www.gnu.org/licenses/>.

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

