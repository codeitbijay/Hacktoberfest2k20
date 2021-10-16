n = input()
b = list(n)
b_rev = b[::-1]
if(b == b_rev):
	print('It is a Palindrome')
else:
	print('It is not a Palindorme')
