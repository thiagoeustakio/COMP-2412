# src/CreditCard/CMakeLists.txt

SET(CMAKE_SUB_APP_NAME "CreditCard")

add_executable(${CMAKE_SUB_APP_NAME}
    TestCreditCard.cpp 
    CreditCard.cpp 
    CreditCard.h
)

# Add source files in the subdirectory
# add_library(CreditCardLib CreditCard.cpp TestCreditCard.cpp)
# Add more source files if needed

# Include directories if needed
# target_include_directories(CreditCard PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Optionally, specify any additional dependencies for CreditCard
