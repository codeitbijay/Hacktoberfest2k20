# Python3 program to find a triplet 
# that sum to a given value 

# returns true if there is triplet with 
# sum equal to 'sum' present in A[]. 
# Also, prints the triplet 
def find3Numbers(A, arr_size, sum): 

	# Fix the first element as A[i] 
	for i in range( 0, arr_size-2): 

		# Fix the second element as A[j] 
		for j in range(i + 1, arr_size-1): 
			
			# Now look for the third number 
			for k in range(j + 1, arr_size): 
				if A[i] + A[j] + A[k] == sum: 
					print("Triplet is", A[i], 
						", ", A[j], ", ", A[k]) 
					return True
	
	# If we reach here, then no 
	# triplet was found 
	return False

# Driver program to test above function 
A = [1, 4, 45, 6, 10, 8] 
sum = 22
arr_size = len(A) 
find3Numbers(A, arr_size, sum) 


