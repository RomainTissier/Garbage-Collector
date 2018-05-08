/**
 * @file even.c
 * @brief Basic isEven function (maybe faster than modulo 2)
 * @author Romain TISSIER
 * @date 12/2017
 */
#include <stdio.h>

/**
 * @brief Test if the parameter is Even
 * @param i integer to test
 * @return If the parameter is Even
 */
int isEven(int i){
    return !(i&1);
}

/**
 * @brief Entry point of the program, test isEven function
 * @return Success
 */
int main(){
    
    // Test isEven function on ten values
    int i;
    for(i=0;i<10;i++)
        printf("isEven(%d) = %d\n",i,isEven(i));
    
    // Return success
    return 0;
}
