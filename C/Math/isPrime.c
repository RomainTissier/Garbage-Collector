#include <stdio.h>
#include <stdint.h>

// Algorithm from wikipedia translated in C 
int isPrime(int number){
	if(number <= 1)
		return 0;
	else if(number <= 3)
		return 1;
	else if(number%2==0 || number%3 ==0)
		return 0;
	int i=5;
	while(i*i<=number){
		if(number%i == 0 || (number%(i + 2) == 0))
			return 0;
		i+=6;
	}
	return 1;
}
