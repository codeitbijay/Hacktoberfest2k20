
/* Backtracking example with NQueens Problem
 * https://en.wikipedia.org/wiki/Eight_queens_puzzle
 */

#include <iostream>


constexpr int ROW = 4;
constexpr int COL = 4;


bool canAdd(int board[ROW][COL], int row, int col) 
{

    for(int i = 0; i < col; i++)
        if(board[row][i])
            return false;


    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(board[i][j])
            return false;

    for(int i = row, j = col; j >= 0 && i < COL; i++, j--)
        if(board[i][j])
            return false;


    return true;

}


bool solve(int board[ROW][COL], int current_column)
{

    if(current_column >= COL)
        return true;


    for(int i = 0; i < ROW; i++)
    {

        if(canAdd(board, i, current_column)) 
        {

            board[i][current_column] = 1;

            if(solve(board, current_column + 1))
                return true;

            board[i][current_column] = 0;
  
        }

    }

    return false;

}


void printBoard(int board[ROW][COL]) 
{

    for(int i = 0; i < ROW; i++) {

        for(int j = 0; j < COL; j++) {
            std::cout << " " << board[i][j] << " ";
        }

        std::cout << std::endl;
    }

}


int main(int argc, char** argv) 
{

    int board[ROW][COL] = { 0 };

    if(solve(board, 0))
        printBoard(board);

    return 0;

}
