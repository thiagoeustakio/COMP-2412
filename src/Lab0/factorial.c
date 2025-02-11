#include <stdio.h>
#include <stdlib.h>

long fact(long n){
    if(0>=n) return 1;
    return fact(n-1)*n;
}

int main(int argc, char** argv){
    printf("N!: \n");

    long nfact = fact(atoi(argv[1]));
    
    printf("%ld\n", nfact);
}