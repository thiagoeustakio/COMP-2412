# src/Lab0/CMakeLists.txt

SET(CMAKE_SUB_APP_NAME "Lab0")

add_executable(fibonacci
    fibonacci.c
)

add_executable(factorial
    factorial.c
)
# add_executable(my_fibo_executable fibonacci.c)

add_executable(my_listADT_example ListADTExample.cpp ListADT.cpp)

add_executable(list_example
    ListADTExample.cpp ListADT.cpp
)
