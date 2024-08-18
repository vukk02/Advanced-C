/*
* File: dish.cpp
* Author: Vo Huynh Anh Vu
* Date: 17/08/2024
* Description: This file contains all the functions/methods to store dish's information
*/


#include "../Header/dish.hpp"
#include <iostream>
#include <string>

using namespace std;


dish::dish()
{
    static int id = 2000;
    this->id = id;
    
    id++;

}
/*
* Class: Dish
* Function: getID
* Description: This function is used for getting ID of dish
* Input:   None
* Output:  return: ID (ID of dish)
*/
int dish::getid()
{
    return this->id;
}
/*
* Class: Dish
* Function: getPrice
* Description: This function is used for getting price of dish
* Input:   None
* Output:  return: price (price of dish)
*/
int dish::getprice()
{
    return this->price;
}
/*
* Class: Dish
* Function: getName
* Description: This function is used for getting name of dish
* Input:   None
* Output:  return: name (name of dish)
*/
string dish::getname()
{
    return this->name;
}
/*
* Class: Dish
* Function: setPrice
* Description: This function is used for setting price of dish
* Input:   _price (price of dish)
* Output:  return: None
*/
void dish::setprice(int price)
{
    this->price = price;
}
/*
* Class: Dish
* Function: setName
* Description: This function is used for setting name of dish
* Input:   _name (name of dish)
* Output:  return: None
*/
void dish::setname(string name)
{
    this->name = name;
}
/*
* Class: Dish
* Function: setID
* Description: This function is used for setting ID of dish
* Input:   _ID (ID of dish)
* Output:  return: None
*/
void dish::setid(int id)
{
    this->id = id;
}