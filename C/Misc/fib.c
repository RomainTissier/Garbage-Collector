//TODO Properly comment and test

#include <stdio.h>

int fib(int n){
    return (n<2) ? n : fib(n-1)+fib(n-2);
}

int main(){
    int i;
    for(i=0;i<10;i++)
        printf("fib(%d) = %d\n",i,fib(i));
}


