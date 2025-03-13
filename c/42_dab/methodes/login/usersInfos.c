#include "usersInfos.h"
#include "../account/create_account.h"
#include "../account/delete.h"
#include "../account/password_crypt.h"
#include "../money/moneyManagement.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE_PATH "..\\users"
#define PIN_LENGTH 4

int login(int userAction) {
    char first_name[50], last_name[50], folder_name[100], full_path[150];

    printf("Firstname: ");
    if (scanf("%49s", first_name) != 1) {
        fprintf(stderr, "Invalid input.\n");
        return EXIT_FAILURE;
    }

    printf("Lastname: ");
    if (scanf("%49s", last_name) != 1) {
        fprintf(stderr, "Invalid input.\n");
        return EXIT_FAILURE;
    }

    snprintf(folder_name, sizeof(folder_name), "%s_%s", last_name, first_name);
    snprintf(full_path, sizeof(full_path), "%s\\%s", BASE_PATH, folder_name);

    if (enterPinCode(full_path) == 0) {
        if (userAction == 1) {
            loggedMenu(full_path);
        } else if (userAction == 2) {
            deleteAccount(full_path);
        }
    } else {
        printf("Error during login.\n");
        return 0;
    }
    return 0;
}

int enterPinCode(char fullPath[]) {
    char file_path[200];
    char *getPinFromFile = NULL;
    long fileSize;
    char userPinEntry[PIN_LENGTH + 1];  // For final \0

    do {
        printf("Choose a 4-digit pin code: ");
        if (scanf("%4s", userPinEntry) != 1) {
            fprintf(stderr, "Invalid input. Please enter a numeric pin.\n");
            while (getchar() != '\n') {}
            continue;
        }

        if (!isValidPin(userPinEntry)) {
            printf("Invalid pin. Please enter exactly 4 digits.\n");
            while (getchar() != '\n');
        }
    } while (!isValidPin(userPinEntry));

    snprintf(file_path, sizeof(file_path), "%s\\pin.txt", fullPath);

    FILE *file = fopen(file_path, "r");
    if (!file) {
        printf("Error, file doesn't exist: %s\n", file_path);
        return EXIT_FAILURE;
    }

    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    if (fileSize == -1) {
        printf("Error determining file size.\n");
        fclose(file);
        return EXIT_FAILURE;
    }

    rewind(file);

    getPinFromFile = (char *)malloc((fileSize + 1) * sizeof(char));
    if (getPinFromFile == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return EXIT_FAILURE;
    }

    size_t bytesRead = fread(getPinFromFile, sizeof(char), fileSize, file)+1;
    if (bytesRead != fileSize) {
        printf("Error reading the full file. Expected %ld bytes, but got %zu bytes.\n", fileSize, bytesRead);
        free(getPinFromFile);
        fclose(file);
        return EXIT_FAILURE;
    }

    getPinFromFile[bytesRead] = '\0';

    if (verify_pin(userPinEntry, getPinFromFile) == 0) {
        free(getPinFromFile);
        fclose(file);
        return 0;
    }
    printf("Invalid pin.\n");
    free(getPinFromFile);
    fclose(file);
    return 1;
}

int loggedMenu(char fullPath[]) {
    int choice;

    do {
        printf("+-------------------+\n");
        printf("What would you do?   \n");
        printf("+-------------------+\n");
        printf("1. Add money\n");
        printf("2. Remove money\n");
        printf("3. View amount\n");
        printf("4. Exit\n");
        printf("Enter your choice: \n");
        printf("---------------------\n");
        printf(">>> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMoney(fullPath);
            break;
            case 2:
                removeMoney(fullPath);
            break;
            case 3:
                printf("You got %f $ on your ATM account. \n", openAmountFile(fullPath));
            break;
            case 4:
                printf("Disconnected successfully!\n");
            break;
            default:
                printf("Invalid choice. Try again.\n");
            break;
        }

    } while (choice != 4);

    return 0;
}
