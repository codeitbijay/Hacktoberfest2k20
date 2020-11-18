#fibonacci series
def fibonacci(n):
    default=[0,1]
    for i in range(0,n-1):
        default.append(default[i]+default[i+1])
    print(default)

if __name__=="__main__":
    print("Enter the value of n")
    n=int(input())
    fibonacci(n)
