/**
 * @file args.c
 * @brief Show how compiler handle Strings
 * @author Romain TISSIER
 * @date 10/2019
 */
#include <stdio.h>

/**
 * @brief Misc enum
 */
typedef enum{
	ZERO,
	ONE,
	TWO,
	THREE
}Number;

/**
 * @brief Return a Number as a String
 * @param number Number to print
 * @return A Number as a String
 */
char* print_Number(Number number){
	char *res;
	switch(number){
		case ZERO: res="ZERO"; break;
		case ONE: res="ONE"; break;
		case TWO: res="TWO"; break;
		case THREE: res="THREE"; break;
		default: res = "UNKNOWN"; break;
	}
	return res;
}

/**
 * @brief Print enum in order to understand how the compiler handle strings
 */
int main(){
	char *res; 
    
	res = print_Chiffre(ZERO);
	printf("Print ZERO : %s @%p\n",res,res);

	res = print_Chiffre(TROIS); 
	printf("Print TROIS : %s @%p\n",res,res);

	res = print_Chiffre(ZERO);
	printf("Print ZERO : %s @%p\n",res,res);

	res = print_Chiffre(TROIS); 
	printf("Print TROIS : %s @%p\n",res,res);

	return 0;
}
