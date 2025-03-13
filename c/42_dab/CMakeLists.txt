cmake_minimum_required(VERSION 3.30)
project(42_dab C)

set(CMAKE_C_STANDARD 11)

add_executable(42_dab main.c
        methodes/account/create_account.c
        methodes/account/create_account.h
        methodes/account/password_crypt.c
        methodes/account/password_crypt.h
        methodes/login/usersInfos.c
        methodes/login/usersInfos.h
        methodes/money/moneyManagement.c
        methodes/money/moneyManagement.h
        methodes/account/delete.c
        methodes/account/delete.h
)
