#include <stdio.h>
#include <stdlib.h>

#include "fibonacci.h"

int main(int argc, char* argv[]) {
    int clArg = atoi(argv[1]); 
    int result = fibonacci(clArg);
    printf("Fibonacci of %d = %d\n", clArg, result);
    return 0;
}             