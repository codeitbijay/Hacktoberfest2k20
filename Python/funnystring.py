#In this challenge, you will determine whether a string is funny or not. To determine whether a string is funny, create a copy of the string in reverse e.g. abc->cba. Iterating through each string, compare the absolute difference in the ascii values of the characters at positions 0 and 1, 1 and 2 and so on to the end. If the list of absolute differences is the same for both strings, they are funny.

#Determine whether a give string is funny. If it is, return Funny, otherwise return Not Funny.

#For example, given the string s=lmnop, the ordinal values of the charcters are [108, 109, 110, 111, 112]. s_reverse = ponml and the ordinals are [112,111,110,109,108]. The absolute differences of the adjacent elements for both strings are [1,1,1,1], so the answer is Funny.

#Function Description
#Complete the funnyString function in the editor below. For each test case, it should return a string, either Funny or Not Funny.

#funnyString has the following parameter(s):

#s: a string to test

#Input Format
#The first line contains an integer , the number of queries.
#The next  lines each contain a string, .

#Constraints
#a<=q<=10
#2<= |s| <= 10000

#Output Format
#For each string s print whether it is Funny or Not Funny on a new line.

#Sample Input
#2
#acxz
#bcxz

#Sample Output
#Funny
#Not Funny

#!/bin/python3

import os

# Complete the funnyString function below.
def funnyString(s):
    a=[ord(c) for c in s]
    arr=[]
    i=0
    j=1
    while(j<=len(a)-1):
        sub=a[i]-a[j]
        arr.append(abs(sub))
        i+=1
        j+=1
    print(arr)
    rarr=arr[::-1]
    print(rarr)
    if arr == rarr:
        return "Funny"
    else:
        return "Not Funny"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    q = int(input())

    for q_itr in range(q):
        s = input()

        result = funnyString(s)

        fptr.write(result + '\n')

    fptr.close()
