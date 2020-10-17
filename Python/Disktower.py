# Problem link: https://www.hackerearth.com/practice/data-structures/queues/basics-of-queues/practice-problems/algorithm/disk-tower-b7cc7a50/description/

def main(data,n):
    initial = n
    dict = {}
    for i in range(n):
        dict[data[i]] = True
        # Check for initial value
        if data[i]==initial:
            s = ''
            while initial in dict:
                s += str(initial) + ' '
                initial -= 1
            print(s)
        else:
            print(' ')
# Function call
if __name__=='__main__':
    n = int(input())
    data = list(map(int, input().split()))
    main(data, n)
