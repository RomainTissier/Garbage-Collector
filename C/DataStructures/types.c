/**
 * @file args.c
 * @brief Print current machine types sizes
 * @author Romain TISSIER
 * @date 12/2017
 */
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

/**
 * @brief Entry point of the program, print basic data types sizes
 * @return success to the Shell
 */
int main(){
    printf("Basic data types sizes :\n");
    
    // Char type
    printf(" * Char :\n");
    printf("    - %d bytes (%d bits)\n",sizeof(char),CHAR_BIT);
    printf("    - Signed : %d to %d\n",SCHAR_MIN,SCHAR_MAX);
    printf("    - Unsigned : 0 to %u\n", UCHAR_MAX);
    
    //Short type 
    printf(" * Short :\n");
    printf("    - %d bytes (%d bits)\n",sizeof(short),sizeof(short)*8);
    printf("    - Signed : %d to %d\n",SHRT_MIN,SHRT_MAX);
    printf("    - Unsigned : 0 to %u\n", USHRT_MAX);    
    
    // Int type 
    printf(" * Int :\n");
    printf("    - %d bytes (%d bits)\n",sizeof(int),sizeof(int)*8);
    printf("    - Signed : %d to %d\n",INT_MIN,INT_MAX);
    printf("    - Unsigned : 0 to %u\n", UINT_MAX);   
    
    // Long type
    printf(" * Long :\n");
    printf("    - %d bytes (%d bits)\n",sizeof(long),sizeof(long)*8);
    printf("    - Signed : %ld to %ld\n",LONG_MIN,LONG_MAX);
    printf("    - Unsigned : 0 to %lu\n", ULONG_MAX);   
    
    // Long type 
    printf(" * Long long:\n");
    printf("    - %d bytes (%d bits)\n",sizeof(long long),sizeof(long long)*8);
    printf("    - Signed : %lld to %lld\n",LLONG_MIN,LLONG_MAX);
    printf("    - Unsigned : 0 to %llu\n", ULLONG_MAX);   
   
    // Print structures sizes 
    printf("Structures types sizes :\n");
    printf(" * size_t : %d bytes (%d bits)\n",sizeof(size_t),sizeof(size_t)*8);
    printf(" * off_t : %d bytes (%d bits)\n",sizeof(off_t),sizeof(off_t)*8);
    printf(" * unsigned long : %d bytes (%d bits)\n",sizeof(unsigned long),sizeof(unsigned long)*8);
    printf(" * unsigned long int : %d bytes (%d bits)\n",sizeof(unsigned long int),sizeof(unsigned long int)*8);
    printf(" * unsigned long long : %d bytes (%d bits)\n",sizeof(unsigned long long),sizeof(unsigned long long)*8);
 
    
    // Other informations 
    printf("Other informations :\n");
    printf(" * System page size : %d bytes (%d bits)\n",getpagesize(),getpagesize()*8);

    // Return success
    return 0; 
}
