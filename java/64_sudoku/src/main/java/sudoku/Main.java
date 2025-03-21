package sudoku;

import sudoku.methods.CreateGrid;
import sudoku.methods.PlaceNumbers;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int howManyNumbers;

        do {
            System.out.print("How many numbers (between 1 and 50)? ");
            while (!scanner.hasNextInt()) {
                System.out.println("Invalid input. Please enter a number.");
                scanner.next();
            }
            howManyNumbers = scanner.nextInt();
        } while (howManyNumbers < 1 || howManyNumbers > 50);

        scanner.close();

        CreateGrid sudokuGrid = new CreateGrid();
        PlaceNumbers placer = new PlaceNumbers(sudokuGrid.grid);
        placer.generateRandomNumbers(howManyNumbers);

        sudokuGrid.printGrid();
        sudokuGrid.saveGridToFile();
    }
}

