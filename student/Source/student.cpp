#include "../Header/student.hpp"

Student::Student(string name, int age, string sex, float math ,float physics, float chemistry)
{   

    static int id = 200000;
    this->id = id;
    id++;
    this->name = name;
    this->age = age;
    this->sex = sex;
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
    cout<<"Id:      "<<this->id<<endl;
    cout<<"Name:    "<<this->name<<endl;
    cout<<"Age:     "<<this->age<<endl;
    cout<<"Sex:     "<<this->sex<<endl;
    cout<<"Math  |  Physics  |  Chemistry     "<<endl;
    cout<<"  "<<this->math<<"        "<<this->physics<<"           "<<this->chemistry<<endl;
    cout<<"Average:   "<<this->average<<endl;
    cout<<"Grade:     ";
    switch (this->grade)
    {
    case d:
        cout<<"Yeu"<<endl;
        break;
    case c:
        cout<<"Trung binh"<<endl;
        break;
    case b:
        cout<<"Kha"<<endl;
        break;
    case a:
        cout<<"Gioi"<<endl;
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
int Student::get_age()
{
    return this->age;
}
string Student::get_name()
{
    return this->name;
}
string Student::get_sex()
{
    return this->sex;
}
void Student::set_name(string name)
{
    this->name = name;
}
void Student::set_sex(string sex)
{
    this->sex = sex;
}
void Student::set_age(int age)
{
    this->age = age;
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

string Student::get_grade()
{
    switch (this->grade)
    {
    case d:
        return "Yeu";
        break;
    case c:
        return "Trung binh";
        break;
    case b:
        return "Kha";
        break;
    case a:
        return "Gioi";
        break;
    default:
        break;
    }
    return "none";
}
grades Student::get_grades()
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

void StudentManager::addStudent()
{  
    cout<<"   Add student"<<endl<<endl;
    int option ;
    string name; 
    string sex;
    int age;
    float math ;
    float physics; 
    float chemistry; 
    again:
    cout<<"Enter name: "; cin>>name;
    cout<<"Enter age:  "; cin>>age;
    cout<<"Enter sex:  "; cin>>sex;
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
    Student sv(name,age,sex,math,physics,chemistry);
    this->database.push_back(sv);
    cout<<"-------------"<<endl;
    sv.displayInfo();
    PRINT_MENU("Add another student ", "Back");
    
    cin>>option;

    HANDLE_OPTION(option,
        CASE_OPTION(1, goto again)
        CASE_OPTION(0, break)
        
    )
     
}

void fixname(Student &item)
{
    
    cout<<"Fix name"<<endl;
    string name;
    cout<<"Please enter new name: ";cin>>name;
    item.set_name(name);
    cout<<"-------"<<endl;
}
void fixage(Student &item)
{       
    cout<<"Fix age"<<endl;
    int age;
    cout<<"Please enter new age: ";cin>>age;
    item.set_age(age);
    cout<<"-------"<<endl;
}         
void fixsex(Student &item)
{   
    cout<<"Fix sex"<<endl;
    string sex;
    cout<<"Please enter new sex: ";cin>>sex;
    item.set_sex(sex);
    cout<<"-------"<<endl;
}     
void fixmath(Student &item)
{
    cout<<"Fix math"<<endl;
    float math;
    cout<<"Please enter new math: ";cin>>math;
    item.set_math(math);
    cout<<"-------"<<endl;
}     
void fixphysics(Student &item)
{
    cout<<"Fix physics"<<endl;
    float physics;
    cout<<"Please enter new physics: ";cin>>physics;
    item.set_physics(physics);
    cout<<"-------"<<endl;
}          
void fixchemistry(Student &item)
{  
    cout<<"Fix chemistry"<<endl;
    float chemistry;
    cout<<"Please enter new chemistry: ";cin>>chemistry;
    item.set_chemistry(chemistry);
    cout<<"-------"<<endl;
                    
}
void StudentManager::updateStudent()
{   
    cout<<"    Update student"<<endl<<endl;
    string name;
    int i=0;
    int id;
    int option;
    begin:
    cout<<"Enter student's name: "; cin>> name;
    cout<<"----------"<<endl;
    cout<<"STT  |    ID        |   Name "<<endl;
    for(Student &item : this->database)
    {
        if (item.get_name() == name)
        {
            cout<<++i<<"    |    "<<item.get_id()<<"    |   "<<item.get_name()<<endl;
        } 
    }
    if(i==0)
    {
        cout<<"Name not found"<<endl;
        goto end;
    }
    cout<<"Please enter the student's id which you want to fix: "; cin>>id;
    cout<<"--------";
    for(Student &item : this->database)
    {
        if (item.get_id() == id)
        {   again:
            item.displayInfo();
            cout<<endl;
            PRINT_MENU("Fix name","Fix age","Fix sex","Fix math","Fix physics","Fix chemistry","Back");
            cin>>option;
            HANDLE_OPTION(option,
                    CASE_OPTION(1, fixname(item))
                    CASE_OPTION(2, fixage(item))
                    CASE_OPTION(3, fixsex(item))
                    CASE_OPTION(4, fixmath(item))
                    CASE_OPTION(5, fixphysics(item))
                    CASE_OPTION(6, fixchemistry(item))
                    CASE_OPTION(0, goto end)
            );
            
            cout<<"Update successful"<<endl;
            item.get_Average();
            item.get_grades();
            PRINT_MENU("Back","Exit");
            cin>>option;
            HANDLE_OPTION(option,
                    CASE_OPTION(1,goto again)
                    CASE_OPTION(0,goto end)
                );
    
            

        }
    }
    // if(item.get_id()!=id)
         cout<<"id unsuitable"<<endl;
     end:;
}


void StudentManager::deleteStudent()
{  
    cout<<"    Delete student"<<endl<<endl;
    string name;
    int i=0;
    int id;
    int option;
    list<Student>::iterator it;
    again:
    cout<<"Enter student's name: "; cin>> name;
    cout<<"----------"<<endl;
    cout<<"STT  |    ID        |   Name "<<endl;
    for(Student &item : this->database)
    {
        if (item.get_name() == name)
        {
            cout<<++i<<"    |    "<<item.get_id()<<"    |   "<<item.get_name()<<endl;
        } 
    }
    if(i==0)
    {
        cout<<"Name not found"<<endl;
        goto end;
    }
    cout<<"Please enter the student's id which you want to fix: "; cin>>id;
    cout<<"--------"<<endl;

    

    for (it = database.begin(); it != database.end(); ++it)
    {
        if (it->get_id() == id)
        {
            database.erase(it);
            cout<<"Delete successful"<<endl;
            cout<<"--------"<<endl;
            goto end;
        }

    }
    cout<<"ID not found"<<endl;
    cout<<"--------"<<endl;
    end:
    PRINT_MENU("Delete another student ", "Back");
    
    cin>>option;

    HANDLE_OPTION(option,
        CASE_OPTION(1, goto again)
        CASE_OPTION(0, break)
        
    );
    
}

void StudentManager::findstudent()
{
    cout<<"    Find student"<<endl<<endl;
    int option;
    int j=0;
    int id;
    int i=0;
    string name;
    again:
    PRINT_MENU("Find by name ","Find by id", "Back");
    
    cin>>option;

    HANDLE_OPTION(option,
        CASE_OPTION(1, goto findbyname)
        CASE_OPTION(2, goto findbyid)
        CASE_OPTION(0, goto end)
        
    )
    findbyname:
    i=0;
    cout<<"    Find by name"<<endl;
    cout<<"Enter student's name:"; cin>>name;
    cout<<"----------"<<endl;
    cout<<"STT\t|\tID\t|\tName\t|\tSex\t|\tAverage\t|\tGrade "<<endl;
    for(Student &item : this->database)
    {
        if (item.get_name() == name)
        {
            cout<<++i<<"\t|\t"<<item.get_id()<<"\t|\t"<<item.get_name()<<"\t|\t"<<item.get_sex()<<"\t|\t";
            printf("%.2f",item.get_Average());
            cout<<"\t|\t"<<item.get_grade()<<endl;
        } 
    }
    if (i==0)
    {
        cout<<"Name not found"<<endl;
    }
    goto next;
    findbyid:
    j=0;
    cout<<"    Find by id"<<endl;
    cout<<"Enter student's id:"; cin>>id;
    cout<<"----------"<<endl;
    cout<<"STT\t|\tID\t|\tName\t|\tSex\t|\tAverage\t|\tGrade "<<endl;
    for(Student &item : this->database)
    {
        if (item.get_id() == id)
        {
            cout<<++i<<"\t|\t"<<item.get_id()<<"\t|\t"<<item.get_name()<<"\t|\t"<<item.get_sex()<<"\t|\t";
            printf("%.2f",item.get_Average()); 
            cout<<"\t|\t"<<item.get_grade()<<endl;
        } 
    }
    if (j==0)
    {
        cout<<"Id not found"<<endl;
    }

    next:
    PRINT_MENU("Find another student ", "Back");
    
    cin>>option;

    HANDLE_OPTION(option,
        CASE_OPTION(1, goto again)
        CASE_OPTION(0, goto end)
        
    );
    end:;
}


bool StudentManager::sortByMath(list<Student>::iterator it1, list<Student>::iterator it2) {
    return it1->get_math() > it2->get_math();
}

bool StudentManager::sortByPhysics(list<Student>::iterator it1, list<Student>::iterator it2) {
    return it1->get_physics() > it2->get_physics();
}

bool StudentManager::sortByChemistry(list<Student>::iterator it1, list<Student>::iterator it2) {
    return it1->get_chemistry() > it2->get_chemistry();
}

bool StudentManager::sortByAverage(list<Student>::iterator it1, list<Student>::iterator it2) {
    return it1->get_Average() > it2->get_Average();
}

bool StudentManager::sortByName(list<Student>::iterator it1, list<Student>::iterator it2) {
    return it1->get_name() > it2->get_name();
}

void StudentManager::sortStudents(bool (StudentManager::*sort)(list<Student>::iterator, list<Student>::iterator)) {
    list<Student>::iterator it1,it2,next_it;   
    for ( it1 = database.begin(); it1 != prev(database.end()); ++it1) {
        for ( it2 = database.begin(); it2 != prev(database.end(), distance(database.begin(), it1) + 1); ++it2) {
                next_it = next(it2);
            if ((this->*sort)(it2, next_it)) {
                iter_swap(it2, next_it);
            }
        }
    }
}

void StudentManager::sort()
{
    cout<<"    Sort student"<<endl<<endl;

    int option;
    again:
    PRINT_MENU("Sort by name ","Sort by math","Sort by physics","Sort by chemistry","Sort by average", "Back");
    
    cin>>option;

    HANDLE_OPTION(option,
        CASE_OPTION(1, sortStudents(StudentManager::sortByName))
        CASE_OPTION(2, sortStudents(StudentManager::sortByMath))
        CASE_OPTION(3, sortStudents(StudentManager::sortByPhysics))
        CASE_OPTION(4, sortStudents(StudentManager::sortByChemistry))
        CASE_OPTION(5, sortStudents(StudentManager::sortByAverage))
        CASE_OPTION(0, break)
        
    );
    int i=0;
    cout<<"STT\t|\tID\t|\tName\t|\tSex\t|\tAverage\t|\tGrade "<<endl;
    for(Student &item : this->database)
    {
        cout<<++i<<"\t|\t"<<item.get_id()<<"\t|\t"<<item.get_name()<<"\t|\t"<<item.get_sex()<<"\t|\t";
            printf("%.2f",item.get_Average());
            cout<<"\t|\t"<<item.get_grade()<<endl;
        
    }
    PRINT_MENU("Sort by other ", "Back");
    
    cin>>option;

    HANDLE_OPTION(option,
        CASE_OPTION(1, goto again)
        CASE_OPTION(0, break)
        
    );
    

}
void StudentManager::displayAllStudents()
{   
    cout<<"    Student list"<<endl<<endl;
    int i=0;
    int option;
    cout<<"STT\t|\tID\t|\tName\t|\tSex\t|\tMath\t|\tPhysics\t|\tChemistry\t|\tAverage\t|\tGrade "<<endl;
    for(Student &item : this->database)
    {
        cout<<++i<<"\t|\t"<<item.get_id()<<"\t|\t"<<item.get_name()<<"\t|\t"<<item.get_sex()<<"\t|\t"
            <<item.get_math()<<"\t|\t"<<item.get_physics()<<"\t|\t"<<item.get_chemistry()<<"\t\t|\t";
            printf("%.2f",item.get_Average());
            cout<<"\t|\t"<<item.get_grade()<<endl;
        
    }
    cout<<"0. Back"<<endl;
    cout<<"Please select function"<<endl;
    cout<<"-----------"<<endl;
    cin>>option;

}

void StudentManager::saveincsv()
{
    cout<<"   Save in file database_sv.csv"<<endl<<endl;
    int i=0;
    int option;
    ofstream file("database_sv.csv");
    
    if (!file.is_open()) {
        cout << "Unable to open file" << endl;
        return;
    }
    
    file <<"STT"<<','<<"ID"<<','<<"Name"<<','<<"Age"<<','<<"Sex"<<','<<"Math"<<','
    <<"Physics"<<','<<"Chemisry"<<','<<"Average"<<','<<"Grade"<<endl;
    for (Student item:database)
    {
        file <<++i<<','<<item.get_id()<<','<<item.get_name()<<','<<item.get_age()<<','
        <<item.get_sex()<<','<<item.get_math()<<','<<item.get_physics()<<','
        <<item.get_chemistry()<<','<<item.get_Average()<<','<<item.get_grade()<<endl;
    }
    cout<<"Save successful"<<endl;
    cout<<"------------"<<endl;
    cout<<"0. Back"<<endl;
    cout<<"Please select function"<<endl;
    cout<<"-----------"<<endl;
    cin>>option;
    file.close();
}


