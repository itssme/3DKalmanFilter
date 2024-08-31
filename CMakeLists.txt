cmake_minimum_required(VERSION 3.10)

# Set the project name
project(KalmanFilter3D)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the pybind11 pybind11 module
set(PYBIND11_FINDPYTHON ON)
find_package(pybind11 CONFIG REQUIRED)

# Define the source and header files
file(GLOB SRC_FILES "src/*.cpp")

# Initialize the library
pybind11_add_module(${PROJECT_NAME} ${SRC_FILES})

# Include the header files
target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/src")

# Create the python module
install(TARGETS ${PROJECT_NAME} DESTINATION .)
