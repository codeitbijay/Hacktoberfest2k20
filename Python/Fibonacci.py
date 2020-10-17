def fibonacci(n):
   if n <= 1:
       return n
   else:
       return(fibonacci(n-1) + fibonacci(n-2))

num = eval(input("Fibonacci Sequence, Enter a Number: "))

if num <= 0:
   print("Plese enter a positive integer")
else:
   print("Fibonacci sequence: ")
   for i in range(num):
       print(fibonacci(i))
