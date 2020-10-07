import java.util.Scanner;

public class Board {
    private Spot[][] boxes = new Spot[8][8];
    private int[][] accessibilityIndex = {{2, 3, 4, 4, 4, 4, 3, 2}, {3, 4, 6, 6, 6, 6, 4, 3}, {4, 6, 8, 8, 8, 8, 6, 4},
                                          {4, 6, 8, 8, 8, 8, 6, 4}, {4, 6, 8, 8, 8, 8, 6, 4}, {4, 6, 8, 8, 8, 8, 6, 4},
                                          {3, 4, 6, 6, 6, 6, 4, 3}, {2, 3, 4, 4, 4, 4, 3, 2}};
    private int currentFile;
    private int currentRow;

    // constructor
    public Board() {
        resetBoard();
        printBoard();
        System.out.println("Enter file and row to place knight:");
        Scanner input = new Scanner(System.in);
        this.currentFile = input.nextInt();
        this.currentRow = input.nextInt();
    }

    public int getCurrentFile() {
        return currentFile;
    }

    public int getCurrentRow() {
        return currentRow;
    }

    public Spot getBox(int file, int row) {
        return boxes[file][row];
    }

    public void setCurrentFile(int currentFile) {
        this.currentFile = currentFile;
    }

    public void setCurrentRow(int currentRow) {
        this.currentRow = currentRow;
    }

    // check if the given box(file, row) is the currentIndex
    public boolean isCurrentIndex(int file, int row) {
        if ((getCurrentFile() == file) && (getCurrentRow() == row))
            return true;
        return false;
    }

    // reset the board and its accessibility to their initial states
    public void resetBoard() {
        for (int row = 0; row < 8; row++) {
            for (int file = 0; file < 8; file++) {
                boxes[file][row] = new Spot(file, row);
                boxes[file][row].setOccupied(0);
                boxes[file][row].setAccessibility(accessibilityIndex[row][file]);
            }
        }
    }

    // print the board and accessibility of each spot side by side
    public void printBoard() {
        System.out.println("  _0_ _1_ _2_ _3_ _4_ _5_ _6_ _7_        _0_ _1_ _2_ _3_ _4_ _5_ _6_ _7_");
        for (int row = 0; row < 8; row++) {
            System.out.printf("%d|", row);
            printFile(row);
            System.out.printf("     %d|", row);
            printRowAccessibility(row);
            System.out.println();
        }
        System.out.println();
    }

    // print each file of a selected row
    public void printFile(int row) {
        for (int file = 0; file < 8; file++) {
            // if a spot is not occupied before
            if (getBox(file, row).getOccupied() == 0) {
                System.out.printf("_%c_|", ' ');
            }
            // if the spot is occupied before
            else {
                // if is the current spot
                if (getBox(file, row).getOccupied() != 0 && isCurrentIndex(file, row)) {
                    System.out.printf("_%c_|", 'K');
                }
                // if is not the current spot
                else {
                    System.out.printf("_%c_|", 'X');
                }
            }
        }
    }

    // print the accessibility of each file in the row
    public void printRowAccessibility(int row) {
        for (int file = 0; file < 8; file++) {
            System.out.printf("_%d_|", getBox(file, row).getAccessibility());
        }
    }
}


