# Bài 14: OOP
## Encapsulation
Tính đóng gói ( Encapsulation) là ẩn đi các property “ mật” khỏi người dùng. Và để làm được điều này, ta sẽ khai báo các property ở quyền truy cập private ( tức là không thể truy cập trực tiếp tới các property này). 
Trong trường hợp ta muốn đọc hoặc ghi các property này, thì ta cung cấp các method ở quyền truy cập public.

## Inheritance
Tính kế thừa ( Inheritance) là khả năng sử dụng lại các property và method của một class trong một class khác. Ta chia chúng làm 2 loại là class cha và class con. Để kế thừa từ class khác, ta dùng ký tự “ : ”.

Tất cả những property và method có quyền truy cập là public và protected ở class cha sẽ được class con kế thừa.

Có 3 kiểu kế thừa là public, private và protected. Những property và method được kế thừa từ class cha sẽ nằm ở quyền truy cập của class con tương ứng với kiểu kế thừa.

## Polymorphism

Tính đa hình ( Polymorphism) có nghĩa là "nhiều dạng" và nó xảy ra khi chúng ta có nhiều class có liên quan với nhau thông qua tính kế thừa.

Tính đa hình là cách dùng những method được kế thừa để thực hiện các tác vụ khác nhau. Điều này giúp chúng ta thể hiện 1 hành động theo nhiều cách khác nhau. ( Function overriding)

Function overloading cung cấp nhiều định nghĩa cho 1 function bằng cách thay đổi số lượng input parameter, kiểu dữ liệu của input parameter.
```c
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
  virtual string test()
  {
    return "Hello person";
  }

  void displayInfo()
  {
    cout << test() << endl;
  }
  
};


class Student : public Person
{
private:
  string School_Name;
  double GPA;
  int StudentID;

public:
  string test()
  {
    return "Hello student";
  }

};


int main()
{
  Person person1;
  person1.displayInfo();
  

  cout << "-----------------------" << endl;
  
  Student student1;
  student1.displayInfo();

  

  return 0;
}

```
## Abstraction

Tính trừu tượng đề cập đến việc ẩn đi các chi tiết cụ thể của một đối tượng và chỉ hiển thị những gì cần thiết để sử dụng đối tượng đó.
