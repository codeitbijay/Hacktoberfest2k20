n=int(input("Enter upper limit of range: "))
sieve=set(range(2,n+1))
while sieve:
    prime=min(sieve)
    print(prime,end="\t")
    sieve-=set(range(prime,n+1,prime))
 
print()

# User need to first enter the value for upper limit of range and store it in a variable n.
# The sieve is initialised to a set which ranges from 2 to n( n+1 is not included).
# The while loop is used to ensure that the sieve is not empty.
# The variable prime is initialised with the least number in the sieve and the prime number is printed.
# The sieve is then removed with all multiples of the prime number.
# The above last two steps will continue till the value of sieve becomes empty.
