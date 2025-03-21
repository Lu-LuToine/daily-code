package sudoku.methods;

import java.io.FileWriter;
import java.io.IOException;

public class CreateGrid {
    int size = 9;
    public int[][] grid;

    public CreateGrid() {
        grid = new int[size][size];
        InitGrid();
    }

    public void InitGrid() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = -1;
            }
        }
    }

    public void printGrid() {
        for (int i = 0; i < size; i++) {
            if (i == 3 || i == 6) {
                System.out.print(" ------------------------------- ");
                System.out.println();
            }
            for (int j = 0; j < size; j++) {
                if (j == 3 || j == 6) {
                    System.out.print(" | ");
                }

                if (grid[i][j] == -1) {
                    System.out.print(" - ");
                } else {
                    System.out.print(" " + grid[i][j] + " ");
                }
            }
            System.out.println();
        }
    }

    public void saveGridToFile() {
        String fileName = "grid.txt";

        try (FileWriter writer = new FileWriter(fileName)) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    writer.write((grid[i][j] == -1 ? "-" : grid[i][j]) + " ");
                    if (j == 2 || j == 5) {
                        writer.write("| ");
                    }
                }
                writer.write("\n");
                if (i == 2 || i == 5) {
                    writer.write("---------------------\n");
                }
            }
            System.out.println("Grid saved in " + fileName);
        } catch (IOException e) {
            System.err.println("Error while save grid : " + e.getMessage());
        }
    }
}
