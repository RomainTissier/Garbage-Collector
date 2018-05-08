/**
 * @file array.c
 * @brief Print how tab are stored in memory
 * @author Romain TISSIER
 * @date 05/2018
 */
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

/**
 * @brief Entry point of the program, print basic data types sizes
 * @return success to the Shell
 */
int main(){
    int tab1[3][3]= {{1,2,3},{4,5,6},{7,8,9}};

    printf("Tab 1 : \n");
    printf("%d %d %d\n",tab1[0][0],tab1[0][1],tab1[0][2]);
    printf("%d %d %d\n",tab1[1][0],tab1[1][1],tab1[1][2]);
    printf("%d %d %d\n",tab1[2][0],tab1[2][1],tab1[2][2]);

    printf("\n");

    int tab2[3][3]={1,2,3,4,5,6,7,8,9};
    printf("Tab 2 : \n");
    printf("%d %d %d\n",tab2[0][0],tab2[0][1],tab2[0][2]);
    printf("%d %d %d\n",tab2[1][0],tab2[1][1],tab2[1][2]);
    printf("%d %d %d\n",tab2[2][0],tab2[2][1],tab2[2][2]);

    // Return success
    return 0; 
}
