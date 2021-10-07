# Python 3.x code to demonstrate star pattern
 
# Function to demonstrate printing pattern
def pypart(n):
    myList = []
    for i in range(1,n+1):
        myList.append("*"*i)
    print("\n".join(myList))
 
# Driver Code
n = 5
pypart(n)
