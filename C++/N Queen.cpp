// C/C++ program to solve N Queen Problem using backtracking 
#include <bits/stdc++.h>
using namespace std;

/* A utility function to print solution */
void printSolution(vector<vector<int>> &board){ 
  int N = board.size();
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < N; j++) 
			printf(" %d ", board[i][j]); 
		printf("\n"); 
	} 
} 

// function to check if a queen can be placed on board[row][col].
bool isSafe(vector<vector<int>> &board, int row, int col) { 
	int i, j; 
	int N = board.size();
	/* Check this row on left side */
	for (i = 0; i < col; i++) 
		if (board[row][i]) 
			return false; 

	/* Check upper diagonal on left side */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
		if (board[i][j]) 
			return false; 

	/* Check lower diagonal on left side */
	for (i = row, j = col; j >= 0 && i < N; i++, j--) 
		if (board[i][j]) 
			return false; 

	return true; 
} 

// A recursive function to solve N Queen problem
bool solveNQUtil(vector<vector<int>> &board, int col){ 
  int N = board.size();
	// If all queens are placed then return true
	if (col >= N) 
		return true; 

	// Consider this column and try placing this queen in all rows one by one */
	for (int i = 0; i < N; i++) { 
		// Check if the queen can be placed on board[i][col]
		if (isSafe(board, i, col)) { 
			// Place this queen in board[i][col]
			board[i][col] = 1; 

			// recur to place rest of the queens
			if (solveNQUtil(board, col + 1)) 
				return true; 

			// If placing queen in board[i][col] doesn't lead to a solution, then remove queen from board[i][col]
			board[i][col] = 0;
		} 
	} 

	return false; 
} 

bool solveNQ(int N){ 
  vector<vector<int>> board(N,vector<int>(N,0));
	if (solveNQUtil(board, 0) == false) { 
		printf("Solution does not exist"); 
		return false; 
	} 

	printSolution(board); 
	return true; 
} 

// driver program to test above function 
int main() {  
  int n; cin>>n;
	solveNQ(n); 
	return 0; 
} 
