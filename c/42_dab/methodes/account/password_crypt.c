#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long hash_djb2(const char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash;
}

unsigned long hashing(const char *userPassword) {
    unsigned long hashed_password = hash_djb2(userPassword);
    return hashed_password;
}


int verify_pin(const char *input_pin, const char *stored_hashed_password) {
    unsigned long hashed_input = hashing(input_pin);
    unsigned long hashed_stored_password = strtoul(stored_hashed_password, NULL, 10);

    if (hashed_input == hashed_stored_password) {
        return 0;
    }

    return 1;
}