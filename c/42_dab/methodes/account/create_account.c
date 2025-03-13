#include "create_account.h"
#include <ctype.h>
#include "password_crypt.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <direct.h>
#include <string.h>

#define BASE_PATH "..\\users"
#define PIN_LENGTH 4

int create_account() {
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

    if (_mkdir(full_path) != 0) {
        fprintf(stderr, "Error creating folder %s: \n", full_path);
        switch (errno) {
            case EACCES:
                fprintf(stderr, "\tYou don't have the necessary permissions.\n");
                break;
            case EEXIST:
                fprintf(stderr, "\tThe folder already exists.\n");
                break;
            default:
                fprintf(stderr, "\tUnknown error occurred.\n");
        }
        return EXIT_FAILURE;
    }

    if (_chdir(full_path) != 0) {
        fprintf(stderr, "Can't move into folder %s.\n", full_path);
        return EXIT_FAILURE;
    }

    char pinCode[PIN_LENGTH + 1 ]; // For final \0
    do {
        printf("Choose a 4-digit pin code: ");
        if (scanf("%4s", pinCode) != 1) {
            fprintf(stderr, "Invalid input. Please enter a numeric pin.\n");
            while (getchar() != '\n');
            continue;
        }

        if (!isValidPin(pinCode)) {
            printf("Invalid pin. Please enter exactly 4 digits.\n");
            while (getchar() != '\n');
        }

    } while (!isValidPin(pinCode));

    unsigned long hashedPinCode = hashing(pinCode);

    FILE *pinFile = fopen("pin.txt", "w");
    if (pinFile == NULL) {
        fprintf(stderr, "Error writing to file.\n");
        return EXIT_FAILURE;
    }

    fprintf(pinFile, "%lu\n", hashedPinCode);
    fclose(pinFile);

    double startAmount;
    printf("Enter the amount you want to deposit: ");
    if (scanf("%lf", &startAmount) != 1) {
        fprintf(stderr, "Invalid input.\n");
        return EXIT_FAILURE;
    }

    FILE *amountFile = fopen("amount.txt", "w");
    if (amountFile == NULL) {
        fprintf(stderr, "Error writing to file.\n");
        return EXIT_FAILURE;
    }

    fprintf(amountFile, "%.2f\n", startAmount);
    fclose(amountFile);

    printf("User account created successfully!\n");

    return EXIT_SUCCESS;
}

int isValidPin(const char *pin) {
    if (strlen(pin) != PIN_LENGTH) {
        printf("Invalid pin length.\n");
        return 0;
    }

    for (int i = 0; i < PIN_LENGTH; i++) {
        if (!isdigit(pin[i])) {
            return 0;
        }
    }

    return 1;
}
