//Cài đặt lớp Date gồm d, m, y
//Định nghĩa các hàm dựng, hàm toán tử ++, --
//để tăng, giảm 01 ngày và hàm toán tử >>, << 
//để nhập xuất 01 ngày
#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;
class Date {
    int d, m, y;
    int sn() const; //tháng m năm y có bao nhiêu ngày
    public:
        Date(int dd = 1, int mm = 1, int yy = 2020);
        friend istream &operator >>(istream &in, Date &x);
        friend ostream &operator <<(ostream &out, const Date &x);
        Date &operator ++ ();                                            //tiền tố ++a; hàm trả về đối tượng đã tăng
        Date operator ++ (int);                                      //hậu tố a++; hàm trả về giá trị của đối tượng trước khi tăng
};
#endif