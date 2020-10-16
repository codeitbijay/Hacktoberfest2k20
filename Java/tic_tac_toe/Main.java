import java.util.*;

public class Main {

  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    boolean reset = true;

    do {
      //creating a new game
      TACTIC myGame = new TACTIC();
      myGame.initializeGameBoard();

      //Deciding Player Type
      int gameType;
      gameType = myGame.decidePlayers();

      //game function
      switch(gameType) {
        case 1:
          do {
            System.out.println("Current Board: ");
            myGame.printGameBoard();
            int row;
            int col;
            do {
              System.out.print("Player " + myGame.getCurrentMarker() + " please enter valid row value: ");
              row = s.nextInt()-1;
              System.out.print("Player " + myGame.getCurrentMarker() + " please enter valid column value: ");
              col = s.nextInt()-1;
            }
            while(!myGame.placeMarker(row,col));
            myGame.changeMarker();
          }
          while(!myGame.checkForWinner() && !myGame.isBoardFull());
          break;

        case 2:
          System.out.println("The User will be Player X.");
          do {
            System.out.println("Current Board: ");
            myGame.printGameBoard();
            int row;
            int col;
            if(myGame.getCurrentMarker() == 'X') {
              do {
                System.out.print("Player " + myGame.getCurrentMarker() + " please enter valid row value: ");
                row = s.nextInt()-1;
                System.out.print("Player " + myGame.getCurrentMarker() + " please enter valid column value: ");
                col = s.nextInt()-1;
              }
              while(!myGame.placeMarker(row,col));
            }
            else {
              do {
                row = myGame.AIMove();
                col = myGame.AIMove();
              }
              while(!myGame.placeMarker(row, col));
            }

            myGame.changeMarker();
          }
          while(!myGame.checkForWinner() && !myGame.isBoardFull());
          break;

        case 3:
          do {
            System.out.println("Current Board: ");
            myGame.printGameBoard();
            int row;
            int col;
            do {
              row = myGame.AIMove();
              col = myGame.AIMove();
            }
            while(!myGame.placeMarker(row,col));
            myGame.changeMarker();
          }
          while(!myGame.checkForWinner() && !myGame.isBoardFull());
          break;
      }


      //game Conclusion
      if(myGame.isBoardFull() && !myGame.checkForWinner()) {
        System.out.println("It's a Tie!");
      }
      else {
        System.out.println("Current Board: ");
        myGame.printGameBoard();
        myGame.changeMarker();
        System.out.println("Player "+myGame.getCurrentMarker()+" Wins!");
        System.out.print("Play Again? Y or N" );
        String x = "y";
        String y = s.nextLine();
        if( !y.equalsIgnoreCase(x)) {
          System.out.println("Thanks for playing!");
          reset = false;
        }
      }
    }

    while(reset == true);
  }
}
