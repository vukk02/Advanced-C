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

