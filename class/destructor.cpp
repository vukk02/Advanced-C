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

