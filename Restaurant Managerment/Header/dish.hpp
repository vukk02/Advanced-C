
/*
* File: dish.h
* Author: Vo Huynh Anh Vu
* Date: 17/08/2024
* Description: This file is a dish header file that program is used for storing dish's information
*/

#ifndef __DISH_HPP__
#define __DISH_HPP__

#include "manager.hpp"
#include "menu.hpp"
#include "staff.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
* Class: Dish
* Description: This class contains basic properties and methods of a Dish object
*/
class dish
{
private:
    int id;
    string name;
    int price;
public:
    //dish(string name, int price);
    dish();
    int getid();
    string getname();
    int getprice();
    void setprice(int price);
    void setname(string name);
    void setid(int id);
};



#endif