#include <stdio.h>
#include <stdlib.h>

#include "methodes/account/create_account.h"
#include "methodes/login/usersInfos.h"

int menu(void);

int main(void) {
    do {
        const int action = menu();
        if (action == 4) {
            printf("Goodbye\n");
            break;
        }
        printf("You chose %d\n", action);
        switch (action) {
            case 1:
                create_account();
            break;
            case 2:
                login(1);
            break;
            case 3:
                login(2);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (1);

    printf("Press Enter twice to exit...");
    getchar();
    getchar();

    return 0;
}

int menu(void) {
    int choice;

    printf("+-------------------+\n");
    printf("Welcome to your ATM !\n");
    printf("+-------------------+\n");
    printf("1. Create account\n");
    printf("2. Login \n");
    printf("3. Delete account\n");
    printf("4. Exit\n");
    printf("Enter your choice: \n");
    printf("---------------------\n");
    printf(">>> ");

    scanf("%d", &choice);
    while(getchar() != '\n');

    return choice;
}
