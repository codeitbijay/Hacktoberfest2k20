#!/bin/python3

import math
import os
import random
import re
import sys

def get_median(queue , median , d):
    count = 0
    i=0
    while count < median:
        count+=queue[i]
        i+=1

    right = i
    i -=1
    if count>median or d%2==1:
        return i
    else:
        while queue[right] ==0:
            right+=1
        return (i+right)/2
# Complete the activityNotifications function below.
def activityNotifications(expenditure, d):
    queue = [0]*201
    ending_length = d
    for i in range(d):
        queue[expenditure[i]]+=1
    if d%2:
        median_left = int(d/2)+1
    else:
        median_left = int(d/2)
    total_length = len(expenditure)

    current = 0
    notification = 0

    while ending_length < total_length:
        median = get_median(queue , median_left , d)
        if expenditure[ending_length]  >= median*2:
            notification += 1
        queue[expenditure[current]]-=1 
        queue[expenditure[ending_length]]+=1
        current+=1
        ending_length+=1
    return notification

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nd = input().split()

    n = int(nd[0])

    d = int(nd[1])

    expenditure = list(map(int, input().rstrip().split()))

    result = activityNotifications(expenditure, d)

    fptr.write(str(result) + '\n')

    fptr.close()
