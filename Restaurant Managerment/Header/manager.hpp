/*
* File: manager.h
* Author: Vo Huynh Anh Vu
* Date: 17/08/2024
* Description: This file is a table header file that program is used for manage restaurant
*/

#ifndef __MANAGER_HPP__
#define __MANAGER_HPP__

#include "menu.hpp"
#include "staff.hpp"
#include "dish.hpp"
#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

/*
* Class: Manager
* Description: This class contains basic properties and methods of a Manager object
*/
class manager
{
private:
    list<dish> menu;
    int table;
public:
    void settable();
    void adddish();
    void updatedish();
    void deletedish();
    void list_dish();
    list <dish> getMenu();
    int gettable();

};

#endif