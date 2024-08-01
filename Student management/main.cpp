#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

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
    float math ;
    float physics; 
    float chemistry; 
    float average ;
    grades grade; 

public:
    Student(string name, float math ,float physics, float chemistry); 
    void displayInfo() ; 
    float get_Average();
    grades get_grade();
    int get_id();
    string get_name();
    void set_name(string name);
    float get_physics();
    float get_chemistry();
    float get_math();
    void set_math(float math);
    void set_physics(float physics);
    void set_chemistry(float chemistry);
    
    
};

Student::Student(string name, float math ,float physics, float chemistry)
{   

    static int id = 100;
    this->id = id;
    id++;
    this->name = name;
    this->math = math;
    this->physics = physics;
    this->chemistry = chemistry;
    assert(math>=0 && math<=10);
    assert(physics>=0 && physics<=10);
    assert(chemistry>=0 && chemistry<=10);


    this->average = (math + physics + chemistry)/3;

    if (get_Average() < 5)
        this->grade = d;
    else if (get_Average() < 7)
        this->grade = c;
    else if (get_Average() < 9)
        this->grade = b;
    else this->grade = a;
}
void Student::displayInfo()
{
    cout<<"id:        "<<this->id<<endl;
    cout<<"name:      "<<this->name<<endl;
    cout<<"math:      "<<this->math<<endl;
    cout<<"physics:   "<<this->physics<<endl;
    cout<<"chemistry: "<<this->chemistry<<endl;
    cout<<"average:   "<<this->average<<endl;
    cout<<"grade:     ";
    switch (this->grade)
    {
    case d:
        cout<<"d"<<endl;
        break;
    case c:
        cout<<"c"<<endl;
        break;
    case b:
        cout<<"b"<<endl;
        break;
    case a:
        cout<<"a"<<endl;
        break;
    default:
        break;
    }

}
float Student::get_Average()
{
    this->average = (math + physics + chemistry)/3;
    return this->average;
}
int Student::get_id()
{
    return this->id;
}
string Student::get_name()
{
    return this->name;
}
void Student::set_name(string name)
{
    this->name = name;
}


float Student::get_math()
{
    return this->math;
}
void Student::set_math(float math)
{
    this->math = math;
}
float Student::get_physics()
{
    return this->physics;
}
void Student::set_physics(float physics)
{
    this->physics = physics;
}
float Student::get_chemistry()
{
    return this->chemistry;
}
void Student::set_chemistry(float chemistry)
{
    this->chemistry = chemistry;
}

grades Student::get_grade()
{
    if (get_Average() < 5)
        this->grade = d;
    else if (get_Average() < 7)
        this->grade = c;
    else if (get_Average() < 9)
        this->grade = b;
    else this->grade = a;
    return this->grade;
}


class StudentManager
{
private:
    vector<Student> database;
public:
    void addStudent(); 
    void updateStudentById(int id); 
    void deleteStudentById(int id); 
    Student* findStudentById(int id); 
    bool sortByName(int i); 
    bool sortByAverage(int i); 
    bool sortById(int i);
    void sortStudents(bool (StudentManager::*sort)(int )); 
    void displayAllStudents();
};
void StudentManager::addStudent()
{
    string name; 
    float math ;
    float physics; 
    float chemistry; 
    
    cout<<"Enter name: "; cin>>name;
    do
    {   
        cout<<"Enter math: "; cin>>math;
    } while (math<0 || math>10);
    do
    {
        cout<<"Enter physics: "; cin>>physics;
    } while (physics<0 || physics>10);
    do
    {
        cout<<"Enter chemistry: "; cin>>chemistry;
    } while (chemistry<0 || chemistry>10);
    Student sv(name,math,physics,chemistry);
    this->database.push_back(sv);
     
}

void StudentManager::updateStudentById(int id)
{
    for(Student &item : this->database)
    {
        if (item.get_id() == id)
        {   again:
            cout<<"Find the student with id: "<<id<<endl;
            cout<<"Enter the information you want to update: "<<endl;
            cout<<"1. Name"<<endl;
            cout<<"2. Math"<<endl;
            cout<<"3. Physics"<<endl;
            cout<<"4. Chemistry"<<endl;
            cout<<"0. Exit"<<endl;
            int a;
            cin>>a;
            switch (a)
            {
            case 1:
            {   string name;
                cout<<"Enter new name: "; cin>>name;
                item.set_name(name);  
                break;
            }
            case 2:
            {   float math;
                cout<<"Enter new math: "; cin>>math;
                item.set_math(math); 
                item.get_grade(); 
                break;
            }
            case 3:
            {   float physics;
                cout<<"Enter new physics: "; cin>>physics;
                item.set_physics(physics); 
                item.get_grade(); 
                break;
            }
            case 4:
            {   float chemistry;
                cout<<"Enter new chemistry: "; cin>>chemistry;
                item.set_chemistry(chemistry);
                item.get_grade();  
                break;
            }
            case 0:
            goto end;
            default:
            {
                cout<<"Enter error:"<<endl;
                break;
            }
            }goto again;

        }
    }
    // if(item.get_id()!=id)
         cout<<"id unsuitable"<<endl;
     end:;
}

void StudentManager::deleteStudentById(int id)
{  
    for (int i = 0; i < this->database.size(); i++)
    {
        if(database[i].get_id() == id)
        {
            cout<<"Find the student with id: "<<id<<endl;
            database.erase(database.begin() + i);
            cout<<"Deleted"<<endl;
        }

    }
    
}
Student* StudentManager::findStudentById(int id)
{
    for (int i = 0; i < this->database.size(); i++)
    {
        if(database[i].get_id() == id)
        {
            return &database[i];
        }

    }
    return nullptr;
}

bool StudentManager::sortById(int i)
{
    return this->database[i].get_id() > this->database[i+1].get_id();
}

bool StudentManager::sortByAverage(int i)
{
    return this->database[i].get_Average() > this->database[i+1].get_Average();
}

bool StudentManager::sortByName(int i)
{
    return this->database[i].get_name() > this->database[i+1].get_name();
}

void StudentManager::sortStudents(bool (StudentManager::*sort)(int))
{
    for (int i = 0; i < this->database.size()-1; i++)
    {
        for (int j = 0; j < this->database.size()-i-1; j++)
        {
            if((this->*sort)(j) )
                swap(this->database[j],this->database[j+1]);
        }
        
    }
    
}

void StudentManager::displayAllStudents()
{
    for(Student item: this->database)
    {
        item.displayInfo();
        cout<<"---------------"<<endl;
    }
}

int main()
{   
    StudentManager sv;
	while (1)
	{
		int option ;
        int id;
		cout << "1. Add a student" << endl;
		cout << "2. Update a student information by ID" << endl;
		cout << "3. Delete a student by ID" << endl;
		cout << "4. Find a student by ID" << endl;
		cout << "5. Sort the list of students by name " << endl;
        cout << "6. Sort the list of students by id " << endl;
        cout << "7. Sort the list of students by average " << endl;
		cout << "8. Display all the list of students" << endl;
		cout << "0. Exit" << endl;
		cout << "Choose an option: ";
		cin >> option;

		switch (option)
		{
		
		case 1:
			sv.addStudent();
			break;
		case 2:
            cout<<"Enter id: "; cin>>id;
			sv.updateStudentById(id);
			break;
		case 3:
            cout<<"Enter id: "; cin>>id;
			sv.deleteStudentById(id);
			break;
		case 4:
            cout<<"Enter id: "; cin>>id;
			sv.findStudentById(id)->displayInfo();
			break;
		case 5:
			sv.sortStudents(StudentManager::sortByName);
			break;
		case 6:
			sv.sortStudents(StudentManager::sortById);
			break;
		case 7:
			sv.sortStudents(StudentManager::sortByAverage);
			break;
		case 8:
			sv.displayAllStudents();
			break;
        case 0:
			cout << "Exit" << endl;
			exit(1);
		default:
			cout << "Invalid option" << endl;
			break;
		}
	}
    return 0;
}