#TODO Clean and comment
from math import *

def smallestPrimeFactor(n):
    i=2
    while i<n:
        if fmod(n,i)==0:
            return i
        i=i+1
    return n

def printFactor(n):
    res=divisor(n)
    print(res)
    if res != n:
        printFactor(n/res)

printFactor(12345)
