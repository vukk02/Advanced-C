#include <iostream>
#include <list>

int main() {
    std::list<int> lst = {1, 2, 3, 4, 5};

    lst.push_back(6);                 // Thêm phần tử vào cuối list
    lst.push_front(0);                // Thêm phần tử vào đầu list

    lst.pop_back();                   // Xóa phần tử cuối list
    lst.pop_front();                  // Xóa phần tử đầu list

    int size = lst.size();            // Lấy kích thước của list

    int first = lst.front();          // Lấy phần tử đầu tiên
    int last = lst.back();            // Lấy phần tử cuối cùng

    std::list<int>::iterator it = lst.begin(); // Lấy iterator đến phần tử đầu tiên
    std::list<int>::iterator end = lst.end();  // Lấy iterator đến phần tử sau phần tử cuối cùng

    lst.insert(it, 10);               // Chèn phần tử vào vị trí cụ thể
    lst.erase(it);                    // Xóa phần tử ở vị trí cụ thể

    lst.clear();                      // Xóa tất cả các phần tử trong list

    return 0;
}