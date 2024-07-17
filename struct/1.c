#include <stdio.h>
#include <string.h>

struct SinhVien{
    char hoten[50];
    char email[50];
    char lop[30];
    double gpa;
};
//Thay struct SinhVien = SinhVien
typedef struct SinhVien SinhVien;

int main(){
    SinhVien s; // struct SinhVien cung duoc
    strcpy(s.hoten, "Nguyen Van 28Tech");
    strcpy(s.email, "28tech@gmail.com");
    strcpy(s.lop, "CNTT");
    s.gpa = 2.1;
    printf("Thong tin sinh vien : \n");
    printf("Ho ten : %s\n", s.hoten);
    printf("Email : %s\n", s.email);
    printf("Lop : %s\n", s.lop);
    printf("Diem gpa : %.2lf\n", s.gpa);
    return 0;
}