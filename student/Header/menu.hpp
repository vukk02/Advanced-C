

#ifndef __Menu__
#define __Menu__

#include "student.hpp"

#define PRINT_MENU_ITEM(number, item) printf("%d. %s\n", number, item)
#define PRINT_MENU(...) \
    do { \
        const char* items[] = {__VA_ARGS__}; \
        int n = sizeof(items) / sizeof(items[0]) - 1; \
        for (int i = 0; i < n; i++) { \
            PRINT_MENU_ITEM(i + 1, items[i]); \
        } \
        PRINT_MENU_ITEM(0, items[n]);\
    } while (0);\
    cout<<endl<<"Please select function: "<<endl;\
    cout<<"-------------"<<endl;
#define CASE_OPTION(number, function) case number: function; break;
#define HANDLE_OPTION(option, ...) \
    switch (option) { \
        __VA_ARGS__ \
        default: printf("Invalid option!\n"); \
    }


void menu(StudentManager sv);







#endif
