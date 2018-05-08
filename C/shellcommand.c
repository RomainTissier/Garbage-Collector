/**
 * @file try_env.c
 * @brief Try to execute Shell command within a specific environment 
 * @author Romain TISSIER
 * @date 12/2017
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Entry point of the program
 * @return success to the Shell
 */
int main(){
	printf("Try environment program\n");

	// We can see that we are not in the same environment
	// The $MYVAR variable is not printed
	system("echo \"Try to print some variable :\"");
	system("MYVAR=coucou");
	system("echo $MYVAR");

	// Return success
	return 0; 
}
