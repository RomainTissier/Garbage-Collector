/**
 * @file args.c
 * @brief Show how C arguments works  
 * @author Romain TISSIER
 * @date 12/2017
 */
#include <stdio.h>

/**
 * @brief Entry point of the program
 * @param argc number of arguments
 * @param argv tab wich contains arguments
 * @return success to the Shell
 */
int main(int argc, char *argv[]){
	printf("Basic C parameters order :\n");

	// Loop over argument and print them
	int i;
	for(i=0;i<argc;i++)
		printf("\tArgv[%d] : %s\n",i,argv[i]);

	// Return success
	return 0; 
}
