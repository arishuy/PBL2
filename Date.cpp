#include "Date.h"
#include <iostream>
using namespace std;
Date::Date(int dd, int mm, int yy ):d(dd),m(mm),y(yy){
    // d = dd;
    // m = mm;
    // y = yy;
}
//cin>>x>>y
istream &operator >>(istream &in, Date &x){
    cout << "Nhap nam: "; in >> x.y;
    cout << "Nhap thang: "; in >> x.m;
    while(x.m < 1 || x.m > 12){
        cout << "Thang khong hop le! Nhap lai: "; in >> x.m;
    }
    cout << "Nhap ngay: "; in >> x.d;
    while(x.d < 1 || x.d > x.sn()){
        cout << "Ngay khong hop le! Nhap lai: "; in >> x.d;
    }
    return in;
}
//cout<<x
ostream &operator <<(ostream &out, const Date &x){
    out<<x.d<<"/"<<x.m<<"/"<<x.y;
    return out;
}
int Date::sn() const //tháng m năm y có bao nhiêu ngày
{
    int songay[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (y %4==0 && y%100!=0|| y%400==0) songay[2] = 29;
    return songay[m];
}

Date &Date::operator ++ (){//tiền tố ++a
    if (d<sn()) d++;
    else {
        d = 1;
        if (m<12) m++;
        else {m=1; y++;}
    }
    return *this;
}
Date Date::operator ++ (int){ //hậu tố a++
    Date t = *this;
    ++(*this);
    return t;
}
