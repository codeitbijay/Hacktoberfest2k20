# Python3 program to find largest rectangle 

  R = 4
  C = 4


	result = [] 

	top_val = 0	 # Top of stack 

	max_area = 0 # Initialize max area in current 
				# row (or histogram) 

	area = 0 # Initialize area with current top 

	# Run through all bars of given 
	# histogram (or row) 
	i = 0
	while (i < C): 
	
		# If this bar is higher than the 
		# bar on top stack, push it to stack 
		if (len(result) == 0) or (row[result[0]] <= row[i]): 
			result.append(i) 
			i += 1
		else: 
		
			
			top_val = row[result[0]] 
			result.pop(0) 
			area = top_val * i 

			if (len(result)): 
				area = top_val * (i - result[0] - 1 ) 
			max_area = max(area, max_area) 
		
	# Now pop the remaining bars from stack 
	# and calculate area with every popped 
	# bar as the smallest bar 
	while (len(result)): 
		top_val = row[result[0]] 
		result.pop(0) 
		area = top_val * i 
		if (len(result)): 
			area = top_val * (i - result[0] - 1 ) 

		max_area = max(area, max_area) 
	
	return max_area 

# Returns area of the largest rectangle 
# with all 1s in A 
def maxRectangle(A): 
	
	# Calculate area for first row and 
	# initialize it as result 
	result = maxHist(A[0]) 

	# iterate over row to find maximum rectangular 
	# area considering each row as histogram 
	for i in range(1, R): 
	
		for j in range(C): 

			# if A[i][j] is 1 then add A[i -1][j] 
			if (A[i][j]): 
				A[i][j] += A[i - 1][j] 

		# Update result if area with current 
		# row (as last row) of rectangle) is more 
		result = max(result, maxHist(A[i])) 
	
	return result 
	
# Driver Code 
if __name__ == '__main__': 
	A = [[0, 1, 1, 0], 
		[1, 1, 1, 1], 
		[1, 1, 1, 1], 
		[1, 1, 0, 0]] 

	print("Area of maximum rectangle is", 
						maxRectangle(A)) 
	

