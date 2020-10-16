#Entering the values that should permutate
Term = input("Enter the term to rotate : ") 
print("Term to be permutate",Term) 

a = Term + '$'
print(a)
X = len(a)
for i in range(X-1,0,-1):
    c = a[i:]+a[:i]
    print(c,Term)
print(a,Term)
