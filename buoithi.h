#ifndef BUOITHI_H
#define BUOITHI_H
#include"Date.h"
#include"DSmonhoc.h"
#include<iostream>
using namespace std;
class buoithi{
    Date ngaythi;
    bool cathi;         // 1=sang; 0=chieu
    DSmonhoc monhoc;
public:
    buoithi(Date ngaythi = Date(1/1/2021), bool cathi = 0, DSmonhoc monhoc = DSmonhoc(0));
    buoithi(const buoithi &);
    ~buoithi();
    friend ostream &operator <<(ostream &out, const buoithi &x);
};
#endif