import java.util.ArrayList;
import java.util.List;

public class Knight {
    // initialize first move, occupy and change accessibility based on the first move
    public void start(Board board) {
        occupySpot(board, board.getBox(board.getCurrentFile(), board.getCurrentRow()));
        changeAccessibility(board);
    }

    // from the list of possible moves, select the moves with the smallest accessibility
    // (if multiple selections with the same smallest accessibility, select the first)
    // occupy and change the accessibility of the selected spot
    public void move(Board board) {
        List<Spot> moves = possibleMove(board);

        Spot spotOfSmallestValue = board.getBox(0, 0);
        int smallestAccessibility = 9;

        for (Spot spot : moves) {
            if (spot.getAccessibility() < smallestAccessibility) {
                spotOfSmallestValue = spot;
                smallestAccessibility = spot.getAccessibility();
            }
        }
        occupySpot(board, spotOfSmallestValue);
        changeAccessibility(board);
    }

    // set the spot as occupied, update currentFile and currentRow
    public void occupySpot(Board board, Spot spot) {
        spot.setOccupied(1);

        board.setCurrentRow(spot.getRow());
        board.setCurrentFile(spot.getFile());
    }

    // change the accessibility the spots affected after a spot is occupied
    public void changeAccessibility(Board board) {
        List<Spot> possibleMoves = possibleMove(board);
        // reduce the accessibility of the boxes that can be accessed by the box just occupied by 1
        for (Spot spot : possibleMoves) {
            int originalAccessibility = spot.getAccessibility();
            spot.setAccessibility(originalAccessibility - 1);
        }
    }

    // return a list of possible moves based on the current spot of the knight
    public List<Spot> possibleMove(Board board) {
        List<Spot> moves = new ArrayList<>();
        int currentFile = board.getCurrentFile();
        int currentRow = board.getCurrentRow();

        // if any of the eight possible jumps are in the board and not occupied before, add to the list
        if (((currentFile - 1) >= 0) && ((currentRow - 2) >= 0)) {
            if (board.getBox(currentFile - 1, currentRow - 2).getOccupied() == 0)
                moves.add(board.getBox(currentFile - 1, currentRow - 2));
        }
        if (((currentFile - 2) >= 0) && ((currentRow - 1) >= 0)) {
            if (board.getBox(currentFile - 2, currentRow - 1).getOccupied() == 0)
                moves.add(board.getBox(currentFile - 2, currentRow - 1));
        }
        if (((currentFile - 2) >= 0) && (((currentRow + 1)) < 8)) {
            if (board.getBox(currentFile - 2, currentRow + 1).getOccupied() == 0)
                moves.add(board.getBox(currentFile - 2, currentRow + 1));
        }
        if (((currentFile - 1) >= 0) && ((currentRow + 2) < 8)) {
            if (board.getBox(currentFile - 1, currentRow + 2).getOccupied() == 0)
                moves.add(board.getBox(currentFile - 1, currentRow + 2));
        }
        if (((currentRow - 1) >= 0) && ((currentFile + 2) < 8)) {
            if (board.getBox(currentFile + 2, currentRow - 1).getOccupied() == 0)
                moves.add(board.getBox(currentFile + 2, currentRow - 1));
        }
        if (((currentRow - 2) >= 0) && ((currentFile + 1) < 8)) {
            if (board.getBox(currentFile + 1, currentRow - 2).getOccupied() == 0)
                moves.add(board.getBox(currentFile + 1, currentRow - 2));
        }
        if (((currentFile + 1) < 8) && ((currentRow + 2) < 8)) {
            if (board.getBox(currentFile + 1, currentRow + 2).getOccupied() == 0)
                moves.add(board.getBox(currentFile + 1, currentRow + 2));
        }
        if (((currentFile + 2) < 8) && ((currentRow + 1) < 8)) {
            if (board.getBox(currentFile + 2, currentRow + 1).getOccupied() == 0)
                moves.add(board.getBox(currentFile + 2, currentRow + 1));
        }

        return moves;
    }
}
