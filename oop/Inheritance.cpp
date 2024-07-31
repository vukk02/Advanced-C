#include <iostream>
#include <string>


using namespace std;

class Person
{
protected:
  string Name;
  int Age;
  string Home_Address;

public:
  string getName()
  {
    return Name;
  }
  void setName(string name)
  {
    Name = name;
  }

  int getAge()
  {
    return Age;
  }
  void setAge(int age)
  {
    Age = age;
  }

  string getAddress()
  {
    return Home_Address;
  }
  void setAddress(string address)
  {
    Home_Address = address;
  }

  void displayInfo()
  {
    cout << "Name: " << Name << endl;
    cout << "Age: " << Age << endl;
    cout << "Address: " << Home_Address << endl;
  }
  
};


class Student : public Person
{
private:
  string School_Name;
  double GPA;
  int StudentID;

public:
  Student()
  {
    static int id = 1000;
    StudentID = id;
    id++;
  }

  string getSchoolName()
  {
    return School_Name;
  }
  void setSchoolName(string school_name)
  {
    School_Name = school_name;
  }

  double getGPA()
  {
    return GPA;
  }
  void setGPA(double gpa)
  {
    GPA = gpa;
  }

  int getID()
  {
    return StudentID;
  }
};


int main()
{
  Person person1;
  person1.setName("Trung");
  person1.setAge(20);
  person1.setAddress("HCM");
  person1.displayInfo();

  cout << "-----------------------" << endl;
  
  Student student1;

  student1.setName("Trungg");
  student1.setAge(24);
  student1.setAddress("HCMM");
  student1.setGPA(8.1);
  student1.setSchoolName("DinhTienHoang");
  student1.displayInfo();

  return 0;
}