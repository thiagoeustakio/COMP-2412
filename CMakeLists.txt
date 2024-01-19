cmake_minimum_required(VERSION 3.1)
SET(CMAKE_APP_NAME "MyProjects")

project(${CMAKE_APP_NAME})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# Add subdirectories, these will serve as "subprojects"
add_subdirectory(src/CreditCard)
add_subdirectory(src/Lab0)
# Add more subdirectories as needed

# Add the executable (assuming it's named 'my_executable')
add_executable(my_top_levelexec main.cpp)

# Link the executable with the targets from the subdirectories
# target_link_libraries(my_executable src/CreditCard src/Lab0)
# Link more libraries if there are additional subdirectories