#include <stdio.h>
#include <stdlib.h>

int fib(int n){
    if(1>=n) return 1;
    return fib(n-1)+fib(n-2); 
}

int main(int argc, char** argv){
    printf("Nth Fibonnaci number: \n");

    int fib_number = fib(atoi(argv[1]));
    
    printf("%d\n", fib_number);
}