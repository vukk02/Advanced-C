

#ifndef __Student__
#define __Student__

#include "menu.hpp"
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <assert.h>
#include <fstream>

using namespace std;

typedef enum{
    d,
    c,
    b,
    a
}grades;

class Student
{
private:
    int id ;
    string name; 
    int age;
    string sex;
    float math ;
    float physics; 
    float chemistry; 
    float average ;
    grades grade; 

public:
    Student(string name, int age, string sex, float math ,float physics, float chemistry); 
    void displayInfo() ; 
    float get_Average();
    string get_grade();
    grades get_grades();
    int get_id();
    string get_name();
    void set_name(string name);
    float get_physics();
    float get_chemistry();
    float get_math();
    void set_math(float math);
    void set_physics(float physics);
    void set_chemistry(float chemistry);
    void set_age(int age);
    void set_sex(string sex);
    int get_age();
    string get_sex();
    
    
};


class StudentManager
{
private:
    list<Student> database;
public:
    void addStudent(); 
    void updateStudent(); 
    void deleteStudent();  
    void findstudent();
    bool sortByName(list<Student>::iterator it1, list<Student>::iterator it2); 
    bool sortByAverage(list<Student>::iterator it1, list<Student>::iterator it2); 
    bool sortByMath(list<Student>::iterator it1, list<Student>::iterator it2);
    bool sortByPhysics(list<Student>::iterator it1, list<Student>::iterator it2);
    bool sortByChemistry(list<Student>::iterator it1, list<Student>::iterator it2);
    void sortStudents(bool (StudentManager::*sort)(list<Student>::iterator, list<Student>::iterator));
    void sort();
    void displayAllStudents();
    void saveincsv();
};
void fixname(Student &item);
void fixage(Student &item);
void fixsex(Student &item);
void fixmath(Student &item);
void fixphysics(Student &item);
void fixchemistry(Student &item);



#endif
