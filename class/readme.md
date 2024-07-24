# Class
Trong C++, từ khóa "class" được sử dụng để định nghĩa một lớp, là một cấu trúc dữ liệu tự định nghĩa có thể chứa dữ liệu và các hàm thành viên liên quan.
 
Class có 3 thuộc tính là: public, private.

public chứa các thành phần công khai (public) được truy cập từ bên ngoài lớp

private chứa các thành phần riêng tư (private) chỉ có thể truy cập bên trong lớp

```c
#include <iostream>

using namespace std;

class HinhChuNhat {

public:
    double chieuDai;
    double chieuRong;
    // Hàm tính diện tích
    double tinhDienTich() {
        return chieuDai * chieuRong;
    }
    void display();
};

void HinhChuNhat::display()
{
   cout << " Hello " << '\n';
}

int main()
{
    HinhChuNhat hinh1;
    hinh1.chieuDai = 10.0;
    hinh1.chieuRong = 5.0;
    hinh1.display();

    cout << "Dien tich: " << hinh1.tinhDienTich() << endl;


    return 0;
}
```
## Constructor
Constructor trong C++ là một method sẽ được tự động gọi khi khởi tạo object. Constructor sẽ có tên trùng với tên của class.
```c
#include <iostream>

using namespace std;

class HinhChuNhat {

public:
    double chieuDai;
    double chieuRong;

    HinhChuNhat(int dai = 5, int rong = 3);
    // Hàm tính diện tích
    double tinhDienTich() {
        return chieuDai * chieuRong;
    }
};

HinhChuNhat::HinhChuNhat(int dai, int rong)
{
   chieuDai = dai;
   chieuRong = rong;
}

int main()
{
    HinhChuNhat hinh1;
    hinh1.chieuDai = 10.0;
    hinh1.chieuRong = 5.0;
    

    cout << "Dien tich: " << hinh1.tinhDienTich() << endl;


    return 0;
}
```
## Destructor
Destructor trong C++ là một method sẽ được tự động gọi khi object được giải phóng. Destructor sẽ có tên trùng với tên của class và thêm ký tự ~ ở phía trước tên.
```c
#include <iostream>

using namespace std;

class HinhChuNhat {

public:
    double chieuDai;
    double chieuRong;

    HinhChuNhat(int dai = 5, int rong = 3);
    ~HinhChuNhat();

    // Hàm tính diện tích
    double tinhDienTich() {
        return chieuDai * chieuRong;
    }
};

HinhChuNhat::HinhChuNhat(int dai, int rong)
{
   chieuDai = dai;
   chieuRong = rong;
}

HinhChuNhat::~HinhChuNhat(){
    cout << "Destructor" <<endl;
}

int main()
{
    HinhChuNhat hinh1(10,5);
    
    

    cout << "Dien tich: " << hinh1.tinhDienTich() << endl;


    return 0;
}

```
## Static
Khi một property trong class được khai báo với từ khóa static, thì tất cả các object sẽ dùng chung địa chỉ của property này.
```c
#include <iostream>

using namespace std;

class HinhChuNhat {

public:
    double chieuDai;
    double chieuRong;
    
    static int var;
};

int HinhChuNhat::var; // khởi tạo địa chỉ cho biến static var

int main()
{
    HinhChuNhat hinh1;
    HinhChuNhat hinh2;
    HinhChuNhat hinh3;

    cout << "address of chieu dai: " << &hinh1.chieuDai << '\n'; 
    cout << "address of chieu dai: " << &hinh2.chieuDai << '\n'; 
    cout << "address of chieu dai: " << &hinh3.chieuDai << '\n'; 

    cout << "address of var: " << &hinh1.var << '\n'; 
    cout << "address of var: " << &hinh2.var << '\n'; 
    cout << "address of var: " << &hinh3.var << '\n'; 


    return 0;
}

```
