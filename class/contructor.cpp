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

