cmake_minimum_required(VERSION 3.2)
project (RougeLiteMaker)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Get source files from src/ and sub directories
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h")

add_definitions(-DSFML_STATIC)

set (INCLUDE_DIRS "")
foreach (_headerFile ${HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES INCLUDE_DIRS)

# Include files
include_directories(${INCLUDE_DIRS} ./include)

# Lib files
LINK_DIRECTORIES(./lib/)

#-llibrary linking. No commas needed

add_library(RougeLiteMaker ${SOURCES})

target_link_libraries(RougeLiteMaker dl glfw3 GL X11 Xi Xrandr Xxf86vm Xinerama Xcursor rt m Box2D pthread)

# Set executable location to /Debug
set_target_properties(RougeLiteMaker PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./Debug/)
