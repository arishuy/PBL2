#ifndef MONHOC_H
#define MONHOC_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class monhoc
{
private:
    string ten, msmh;

public:
    monhoc();
    monhoc(const monhoc &);
    ~monhoc();
    string getten() const { return ten; };                       // lấy tên môn học
    friend istream &operator>>(istream &, monhoc &);              // đa năng hóa toán tử nhập
    friend ostream &operator<<(ostream &, const monhoc &);       // đa năng hóa toán tử xuất
};
typedef class List DSmonhoc;
class List
{
private:
    monhoc *data;
    int size;

public:
    List(int size = 0);
    List(const List &); 
    ~List();
    int getSize() const { return size; };
    monhoc &operator[](int n) const { return data[n]; };        // truy xuất phần tử
    friend void doiSize(List &, int oldsize, int newsize);      // đổi kích thước danh sách
    List &operator+(monhoc &);                                  // thêm vào cuối danh sách
    void createList(ifstream &);                                // tạo danh sách
    friend ostream &operator<<(ostream &, const List &);        // đa năng hóa toán tử xuất
    int getIndex(string s) const;       // lấy vị trí môn học của sinh viên trong danh sách môn học để đưa vào mảng
};
#endif