a = int(input("Enter a no:"))
sum = 0
n = a
while(n>0):
    d = n % 10
    sum=sum*10 + d
    n = n // 10
if(a == sum):
    print("Palindrome detected")
else:
    print("Palindrome not detected")
