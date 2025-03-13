#include "moneyManagement.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double addMoney(char fullPath[]) {
    double money;
    double startMoney = openAmountFile(fullPath);

    if (startMoney == -1) {
        return -1;
    }

    printf("Current balance: %.2f\n", startMoney);
    printf("Enter money to add: ");

    if (scanf("%lf", &money) != 1 || money < 0) {
        printf("Invalid input. Please enter a positive number.\n");
        return -1;
    }

    double totalMoney = startMoney + money;

    if (updateAmountFile(fullPath, totalMoney) != 0) {
        return -1;
    }
    printf("Added %.2f $ successfully \nCurrent balance: %.2f\n", money, totalMoney);

    return totalMoney;
}

double removeMoney(char fullPath[]) {
    double money;
    double startMoney = openAmountFile(fullPath);
    if (startMoney == -1) {
        return -1;
    }

    printf("Current balance: %.2f\n", startMoney);
    printf("Enter money to remove: ");

    if (scanf("%lf", &money) != 1 || money < 0) {
        printf("Invalid input. Please enter a positive number.\n");
        return -1;
    }

    if (startMoney - money < 0) {
        printf("Not enough money.\n");
        return -1;
    } else {
        double totalMoney = startMoney - money;
        if (updateAmountFile(fullPath, totalMoney) != 0) {
            return -1;
        }

        printf("Removed %.2f $ successfully \nCurrent balance: %.2f\n", money, totalMoney);
        return totalMoney;
    }
}

double openAmountFile(char fullPath[]) {
    char file_path[200];
    double amountFromFile = 0.0;

    if (snprintf(file_path, sizeof(file_path), "%s/amount.txt", fullPath) >= sizeof(file_path)) {
        printf("Error: File path too long.\n");
        return -1;
    }

    FILE *file = fopen(file_path, "r");
    if (!file) {
        printf("Error, file doesn't exist: %s\n", file_path);
        return -1;
    }

    if (fscanf(file, "%lf", &amountFromFile) != 1) {
        printf("Error reading the amount from the file: %s\n", file_path);
        fclose(file);
        return -1;
    }

    fclose(file);
    return amountFromFile;
}

int updateAmountFile(char fullPath[], double totalMoney) {
    char file_path[200];
    if (snprintf(file_path, sizeof(file_path), "%s/amount.txt", fullPath) >= sizeof(file_path)) {
        printf("Error: File path too long.\n");
        return -1;
    }

    FILE *file = fopen(file_path, "w");
    if (!file) {
        printf("Error opening file for writing: %s\n", file_path);
        return -1;
    }

    if (fprintf(file, "%.2f\n", totalMoney) < 0) {
        printf("Error writing to file: %s\n", file_path);
        fclose(file);
        return -1;
    }

    fclose(file);
    return 0;
}
