##Zaidan Pratama

from math import sqrt
from random import randint

numpoint = []
n = int(input('Insert number of point pairs that you want to search the closest range: '))
for i in range (0,n):
    numpoint.append([randint(0,100),randint(0,100)])

print('Point pairs:\n',numpoint)


def countrange(lis):
    lisrange = []
    for i in range (0,len(lis)-1):
        for j in range (i+1,len(lis)):
            pointrange = sqrt((lis[i][0]-lis[j][0])**2 + (lis[i][1]-lis[j][1])**2)
            lisrange.append(pointrange)
            print('Point: ',lis[i], 'Point: ',lis[j],': ',pointrange)
    return min(lisrange)

print('Closest range:\n',countrange(numpoint))
