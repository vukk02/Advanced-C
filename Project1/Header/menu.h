/*
* File: menu.h
* Author: Vo Huynh Anh Vu
* Date: 15/07/2024
* Description: This file is a menu header file that is used to manage building  
*/


#ifndef __MENU_H
#define __MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINT_MENU_ITEM(number, item) printf("%d. %s\n", number, item)
#define PRINT_MENU(...) \
    do { \
        const char* items[] = {__VA_ARGS__}; \
        int n = sizeof(items) / sizeof(items[0]); \
        for (int i = 0; i < n; i++) { \
            PRINT_MENU_ITEM(i + 1, items[i]); \
        } \
    } while (0)
#define CASE_OPTION(number, function) case number: function; break;
#define HANDLE_OPTION(option, ...) \
    switch (option) { \
        __VA_ARGS__ \
        default: printf("Invalid option!\n"); \
    }


void input(Member* member);
void feature1(const char* filename);
void feature2(const char* filename);
void feature3(const char* filename);
void feature4(const char* filename);
void feature5(const char* filename);
void menu(const char* filename);

#endif