public class KnightsTour {
    public static void main(String[] args) {
        // create objects
        Board board = new Board();
        Knight knight = new Knight();

        // initialize the tour
        System.out.println("Turn 1");
        System.out.println("             Board                                 Accessibility");
        knight.start(board);
        board.printBoard();

        // continue the tour until all spots on the board are filled
        for (int i = 2; i <= 64; i++) {
            System.out.printf("Turn %d%n", i);
            System.out.println("             Board                                 Accessibility");
            knight.move(board);
            board.printBoard();
        }
    }
}
