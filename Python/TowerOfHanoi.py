# Recursive Solution
def TowerOfHanoi(n, src, dst, tmp): 
    if n > 0:
        TowerOfHanoi(n - 1, src, tmp, dst) 
        print ("Move disk", n, "from rod", src, "to rod", dst )
        TowerOfHanoi(n - 1, tmp, dst, src) 

# Driver code
n=int(input("Enter Number of Disks : "))
TowerOfHanoi(n, 'Source', 'Destination', 'Auxillary')
