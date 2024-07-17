/*
* File: main.c
* Author: Vo Huynh Anh Vu
* Date: 15/07/2024
* Description: This file is used to manage building 
*/


#include "resident.c"
#include "menu.c"



int main(){
    const char* filename = "members.csv";
    menu(filename);
    
    return 0;

}