/* C/C++ program to solve Rat in a Maze problem using backtracking */
#include <bits/stdc++.h>
using namespace std;
bool solveMazeUtil(vector<vector<int>> &maze, int x, int y, vector<vector<int>> &sol);

// function to print  matrix
void printSolution(vector<vector<int>> &sol)
{
  int N = sol.size();
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      printf(" %d ", sol[i][j]);
    printf("\n");
  }
}

// function to check if x, y is valid index for N*N maze
bool isSafe(vector<vector<int>> &maze, int x, int y)
{
  int N = maze.size();
  // if (x, y outside maze) return false
  if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
    return true;
  return false;
}

// function to solve the Maze problem using Backtracking
bool solveMaze(vector<vector<int>> &maze)
{
  int n = maze.size();
  vector<vector<int>> sol(n, vector<int>(n, 0));

  if (solveMazeUtil(maze, 0, 0, sol) == false)
  {
    printf("Solution doesn't exist");
    return false;
  }

  printSolution(sol);
  return true;
}

// function to solve Maze problem
bool solveMazeUtil(vector<vector<int>> &maze, int x, int y, vector<vector<int>> &sol)
{
  int N = maze.size();
  // if (x, y is goal) return true
  if (x == N - 1 && y == N - 1 && maze[x][y] == 1)
  {
    sol[x][y] = 1;
    return true;
  }

  // Check if maze[x][y] is valid
  if (isSafe(maze, x, y) == true)
  {
    // mark x, y as part of solution path
    sol[x][y] = 1;

    // Move forward in x direction
    if (solveMazeUtil(maze, x + 1, y, sol) == true)
      return true;

    // If moving in x direction doesn't give solution then Move down in y direction
    if (solveMazeUtil(maze, x, y + 1, sol) == true)
      return true;

    // If none of the above movements work then BACKTRACK
    sol[x][y] = 0;
    return false;
  }

  return false;
}

// driver program to test above function
int main()
{
  int n;
  cin >> n;
  vector<vector<int>> maze(n, vector<int>(n, 0));
  for (auto &row : maze)
  {
    for (auto &cell : row)
      cin >> cell;
  }

  solveMaze(maze);
  return 0;
}
