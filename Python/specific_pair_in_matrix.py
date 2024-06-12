

import sys 
N = 5

def findMaxValue(mat): 

	maxValue = -sys.maxsize -1

	maxArr = [[0 for x in range(N)] 
				for y in range(N)] 


	maxArr[N - 1][N - 1] = mat[N - 1][N - 1] 

	maxv = mat[N - 1][N - 1]; # Initialize max 
	for j in range (N - 2, -1, -1): 
	
		if (mat[N - 1][j] > maxv): 
			maxv = mat[N - 1][j] 
		maxArr[N - 1][j] = maxv 
	
	# preprocess last column 
	maxv = mat[N - 1][N - 1] # Initialize max 
	for i in range (N - 2, -1, -1): 
	
		if (mat[i][N - 1] > maxv): 
			maxv = mat[i][N - 1] 
		maxArr[i][N - 1] = maxv 

 
	for i in range (N - 2, -1, -1): 
	
		for j in range (N - 2, -1, -1): 
		
			# Update maxValue 
			if (maxArr[i + 1][j + 1] -
				mat[i][j] > maxValue): 
				maxValue = (maxArr[i + 1][j + 1] -
									mat[i][j]) 

			# set maxArr (i, j) 
			maxArr[i][j] = max(mat[i][j], 
						max(maxArr[i][j + 1], 
							maxArr[i + 1][j])) 
		
	return maxValue 


mat = [[ 1, 2, -1, -4, -20 ], 
	[-8, -3, 4, 2, 1 ], 
	[ 3, 8, 6, 1, 3 ], 
	[ -4, -1, 1, 7, -6] , 
	[0, -4, 10, -5, 1 ]] 
					
print ("Maximum Value is", 
		findMaxValue(mat)) 


