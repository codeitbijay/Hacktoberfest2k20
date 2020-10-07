public class Spot {
    private int file;
    private int row;
    private int occupied;
    private int accessibility;

    public Spot(int file, int row) {
        this.file = file;
        this.row = row;
    }

    // getters
    public int getFile() {
        return file;
    }

    public int getRow() {
        return row;
    }

    public int getOccupied() {
        return occupied;
    }

    public int getAccessibility() {
        return accessibility;
    }

    // setters
    public void setFile(int file) {
        this.file = file;
    }

    public void setRow(int row) {
        this.row = row;
    }

    public void setOccupied(int occupied) {
        this.occupied = occupied;
    }

    public void setAccessibility(int accessibility) {
        this.accessibility = accessibility;
    }
}
