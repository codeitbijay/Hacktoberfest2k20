# this code contains a class to rotate the image embedding(2D matrix)

class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """

        for row in range(len(matrix)):
            for col in range(row, len(matrix[0])):
                matrix[row][col],  matrix[col][row] = matrix[col][row], matrix[row][col]
                
        for row in range(len(matrix)):
            start = 0
            end = len(matrix[0])-1
            while(start<end):
                matrix[row][start], matrix[row][end] = matrix[row][end], matrix[row][start]
                start+=1
                end-=1
                        
        return matrix
