## @file even.c
#  @brief Basic isEven function (maybe faster than modulo 2)
#  @author Romain TISSIER
#  @date 12/2017
from math import *

## @brief return the smallest prime factor of a given number
#  @param n integer to decompose
#  @return the smallest prime factor of n 
def smallestPrimeFactor(n):
    i=2
    while i<n:
        if fmod(n,i)==0:
            return i
        i=i+1
    return n

## @brief print factor of a given number
#  @param n integer to decompose
def printFactor(n):
    res=smallestPrimeFactor(n)
    print(res)
    if res != n:
        printFactor(n/res)

printFactor(12345)
