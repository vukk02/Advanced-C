/*
* File: manager.h
* Author: Vo Huynh Anh Vu
* Date: 17/08/2024
* Description: This file is a table header file that program is used for staff 
*/



#ifndef __STAFF_HPP__
#define __STAFF_HPP__

#include "menu.hpp"
#include "manager.hpp"
#include "dish.hpp"

#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

typedef struct {
    int num;
    dish di;
}Order;
typedef struct{
    list<Order> ta;
    string status="o";
}table;

/*
* Class: staff
* Description: This class contains basic properties and methods of a staff object
*/
class staff
{
private:
    vector<table> tables;
    list<dish> menu;
    int numtable;
public:
    
    void setmenu(list<dish>menu);
    void order();
    void cancle();
    void list_ordered();
    void checkout();
    int getnumtable();
    string getstatus(int num);
    void setnumtable(int num);
    void resizeTables(int newsize);


};


#endif