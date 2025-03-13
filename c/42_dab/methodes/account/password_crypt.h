#ifndef PASSWORD_CRYPT_H
#define PASSWORD_CRYPT_H

#endif //PASSWORD_CRYPT_H

unsigned long hash_djb2(const char *str);
unsigned long hashing(const char *userPassword);
int verify_pin(const char *input_pin, const char *stored_password);
