#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main()
{
   vector<int> v;

    // Thêm phần tử vào vector
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
   // Chèn số 25 vào vị trí thứ 2
    v.insert(v.begin() + 1, 25);

   // Xóa phần tử tại vị trí thứ 3
    v.erase(v.begin() + 2);

   vector<int>::iterator it = v.begin(); // Lấy iterator đến phần tử đầu tiên
   vector<int>::iterator end = v.end();  // Lấy iterator đến phần tử sau phần tử cuối cùng
    // Duyệt qua các phần tử trong vector và in ra màn hình
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
   v.clear();                      // Xóa tất cả các phần tử trong vector


return 0;
}