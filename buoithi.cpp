#include"buoithi.h"
#include<iostream>
using namespace std;
buoithi::buoithi(Date ngaythi, bool cathi, DSmonhoc monhoc)
:ngaythi(ngaythi),cathi(cathi),monhoc(monhoc){}
buoithi::buoithi(const buoithi &other){
    this->ngaythi = other.ngaythi;
    this->cathi = other.cathi;
    this->monhoc = other.monhoc;
}
buoithi::~buoithi(){

}
ostream &operator <<(ostream &out, const buoithi &x){
    out<<"Ngay "<<x.ngaythi<<" ca";
    if(x.cathi) out<<" sang";
    else out<<" chieu";
    out<<" gom cac mon:\n";
    out<<x.monhoc;
    return out;
}
