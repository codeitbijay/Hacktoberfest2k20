#Program to find Sum of a Geometric Progression
# Author: @FaizAlam 
import cmath
def SumofGP(a,r,n):
    # sum = a(r^n -1)/(r-1)
    S = a*(pow(r,n) -1)/(r-1)
    print(S)

SumofGP(1,2,4)     
