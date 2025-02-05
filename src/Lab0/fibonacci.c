#include <stdio.h>
#include <stdlib.h>

int fibo(int n){
    if (n<=1) return 1;
    return fibo(n-1)+fibo(n-2);
}

int main(int argc, char** argv){
    for (int i=1; i<argc; i++){
        printf("%dth Fibonacci number is %d\n", atoi(argv[i]), fibo(atoi(argv[i])));
    }
}