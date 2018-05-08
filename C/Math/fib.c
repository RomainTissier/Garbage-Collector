/**
 * @file fib.c
 * @brief Basic Fibonacci function
 * @author Romain TISSIER
 * @date 12/2017
 */
#include <stdio.h>

/**
 * @brief Compute Fibonacci function 
 * @param n Fibonacci parameters 
 * @return Result of the Fibonacci
 */
int fib(int n){
    return (n<2) ? n : fib(n-1)+fib(n-2);
}

/**
 * @brief Entry point of the program, it tests the fib() function
 * @return success to the Shell
 */
int main(){

    // Test Fibonacci function on ten values
    int i;
    for(i=0;i<10;i++)
        printf("fib(%d) = %d\n",i,fib(i));
    
    // Return success to the Shell
    return 0;
}


