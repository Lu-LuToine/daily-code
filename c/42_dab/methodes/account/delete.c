#include "delete.h"

#include <direct.h>
#include <stdio.h>
#include <stdlib.h>

int deleteAccount(char fullPath[]) {
    char pinPath[1024], amountPath[1024];

    snprintf(pinPath, sizeof(pinPath), "%s\\pin.txt", fullPath);
    snprintf(amountPath, sizeof(amountPath), "%s\\amount.txt", fullPath);

    if (remove(pinPath) != 0) {
        printf("Error deleting pin.txt\n");
    }

    if (remove(amountPath) != 0) {
        printf("Error deleting amount.txt\n");
    }

    if (rmdir(fullPath) == 0) {
        printf("User deleted successfully\n");
        return 0;  // Success
    } else {
        printf("Error deleting the directory\n");
        return 1;  // Error
    }
}

