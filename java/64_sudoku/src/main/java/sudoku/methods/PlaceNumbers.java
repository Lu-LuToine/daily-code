package sudoku.methods;

import java.util.Random;

public class PlaceNumbers {
    private int[][] grid;
    private final int size = 9;

    public PlaceNumbers(int[][] grid) {
        this.grid = grid;
    }


    public void generateRandomNumbers(int count) {
        Random rand = new Random();
        int placed = 0;

        while (placed < count) {
            int row = rand.nextInt(size);
            int col = rand.nextInt(size);
            int num = rand.nextInt(9) + 1;

            if (grid[row][col] == -1 && isValidPlacement(row, col, num)) {
                grid[row][col] = num;
                placed++;
            }
        }
    }

    public boolean isValidPlacement(int row, int col, int num) {

        for (int i = 0; i < size; i++) {
            if (grid[row][i] == num || grid[i][col] == num) {
                return false;
            }
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[startRow + i][startCol + j] == num) {
                    return false;
                }
            }
        }

        return true;
    }
}
