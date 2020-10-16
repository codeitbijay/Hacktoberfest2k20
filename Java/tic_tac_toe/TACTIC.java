import java.util.*;

public class TACTIC {
	private char[][] gameBoard;
	private char currentMarker;
	static Scanner s = new Scanner(System.in);

	//default constructor
	public	TACTIC() {
		gameBoard = new char[3][3];
        currentMarker = 'X';
        initializeGameBoard();
	}
	//get current marker
	public  char getCurrentMarker() {
		return currentMarker;
	}

	//initializer class- resets class
	public void initializeGameBoard() {
		for(int x=0; x<3; x++){
			for(int y=0; y<3; y++){
				gameBoard[x][y] = '*';
			}
		}
	}

	//print current gameBoard out for user to view
	public void printGameBoard() {
		for(int x=0; x<3; x++){
			for(int y=0; y<3; y++){
				System.out.print(gameBoard[x][y] + "|");
			}
			System.out.println();
			System.out.println("-------");
		}

	}

	//check for a winner
	public boolean checkForWinner() {

		if(checkRows() == true) {return true;}
		else if(checkColumns() == true) {return true;}
		else if(checkDiagonals() == true) {return true;}
		else return false;
	}

	//check rows
	public boolean checkRows() {
		boolean value = false;
		for(int y=0; y<3;y++) {
			if((gameBoard[0][y] != '*')&&(gameBoard[0][y]==gameBoard[1][y] && gameBoard[1][y]==gameBoard[2][y])) {
				value = true;
			}
		}
		return value;
	}

	//check columns
	public boolean checkColumns() {
		boolean value = false;
		for(int x=0; x<3;x++) {
			if((gameBoard[x][0] != '*')&&(gameBoard[x][0]==gameBoard[x][1] && gameBoard[x][1]==gameBoard[x][2])) {
				value = true;
			}
		}
		return value;
	}

	//check diagonals
	public boolean checkDiagonals() {
		boolean value = false;
		if((gameBoard[1][1] != '*')&&(gameBoard[0][0]==gameBoard[1][1] && gameBoard[1][1]==gameBoard[2][2])) {
			value = true;
		}
		else if((gameBoard[1][1] != '*')&&(gameBoard[0][2]==gameBoard[1][1] && gameBoard[1][1]==gameBoard[2][0])) {
			value = true;
		}
		return value;
	}

	//change player marker
	public void changeMarker() {
		if(currentMarker == 'X') {
			currentMarker = 'O';
		}
		else {
			currentMarker = 'X';
		}
	}

	//place move on board
	public boolean placeMarker(int row, int col) {
		if (row < 3 && row >= 0 ) {
			if(col < 3 && col >= 0) {
				if(gameBoard[row][col] == '*') {
					gameBoard[row][col] = currentMarker;
					return true;
				}

			}

		}
		return false;
	}

	//check to see if board is full
	public boolean isBoardFull() {
		boolean full = true;
		for(int x=0;x<3;x++) {
			for(int y=0; y<3;y++) {
				if(gameBoard[x][y]=='*')
					full = false;
			}
		}
		return full;
	}

	//Computer Player
	public  int AIMove() {
		int x = 0;
		x = (int) (Math.random()*4);
		return (x);
	}

	//Deciding Players
	public int decidePlayers() {
		int x;
		System.out.println("Please Choose Game Type via Number:\n1.) Player vs. Player\n2.) Player vs. Computer\n3.) Computer vs. Computer");
		x = s.nextInt();
		return x;
	}

}
