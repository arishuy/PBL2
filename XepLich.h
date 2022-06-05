#ifndef XEPLICH_H
#define XEPLICH_H
#include "DSmonhoc.h"
#include "DSsinhvien.h"
#include "Date.h"
#include "buoithi.h"
#include <iostream>
#include <fstream>
using namespace std;
class XepLich{
    int **array;                                // ma trận kề
    int *cov;                                   // mảng lưu màu của đỉnh
    int n;                                      // số đỉnh
    DSmonhoc listMH;
    DSsinhvien listSV;
    Date ngaythi;
public:
    XepLich();
    XepLich(DSmonhoc &, DSsinhvien &);
    ~XepLich();
    void putArray();                            // đưa dữ liệu vào mảng
    void showArray();                           // 
    bool check(int color, int i);               // kiểm tra đỉnh i có kề đỉnh j không để tô màu
    int color1(int color);                      // hàm tô 1 màu cho nhiều đỉnh nhất có thể
    void colorAll();                            // hàm tô màu tất cả các đỉnh
    void setDate(Date &);                       // Nhập ngày thi
    void print();                               // in kết quả lịch thi ra màn hình
    void write(ofstream &fileout);              // viết kết quả lịch thi vào file
};
#endif