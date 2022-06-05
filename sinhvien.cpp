#include "DSsinhvien.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;
sinhvien::sinhvien()
{
    mssv = "";
    hoten = "";
}
sinhvien::sinhvien(const sinhvien &sv){
    this->mssv = sv.mssv;
    this->hoten = sv.hoten;
    this->somonhoc = sv.somonhoc;
    this->mh = new string [somonhoc];
    for(int i = 0; i < somonhoc; i++)
        this->mh[i] = sv.mh[i];
}
sinhvien::~sinhvien()
{
}
istream &operator>>(istream &in, sinhvien &sv)
{
    getline(in, sv.mssv, '-');
    getline(in, sv.hoten, '-');
    string somonhoc;
    getline(in, somonhoc, '-');
    stringstream sst(somonhoc);
    sst >> sv.somonhoc;
    int n = sv.somonhoc;
    sv.mh = new string[n];
    for (int i = 0; i < n - 1; i++)
    {
        getline(in, sv.mh[i], ',');
        for(int j = 0; j < sv.mh[i].length(); j++)
            sv.mh[i][j] = toupper(sv.mh[i][j]);
    }
    getline(in, sv.mh[n - 1]);
    for(int j = 0; j < sv.mh[n - 1].length(); j++)
            sv.mh[n - 1][j] = toupper(sv.mh[n - 1][j]);
    return in;
}
ostream &operator<<(ostream &out, const sinhvien &sv)
{
    out << sv.mssv << "\t" << sv.hoten << "\t";
    for (int i = 0; i < sv.somonhoc - 1; i++)
    {
        out << sv.mh[i] << ",";
    }
    out << sv.mh[sv.somonhoc - 1] << endl;
    return out;
}
void sinhvien::nhap()
{
    cout << "MSSV: ";
    cin >> mssv;
    cout << "Ho va ten: ";
    cin.ignore();
    getline(cin, hoten);
    cout << "So mon hoc: ";
    cin >> somonhoc;
    cin.ignore();
    mh = new string[somonhoc];
    cout << "Danh sach mon hoc: ";
    for (int i = 0; i < somonhoc - 1; i++){
        getline(cin, mh[i], ',');
        for(int j = 0; j < mh[i].length(); j++)
            mh[i][j] = toupper(mh[i][j]);
    }
    getline(cin, mh[somonhoc - 1]);
    for(int j = 0; j < mh[somonhoc - 1].length(); j++)
            mh[somonhoc - 1][j] = toupper(mh[somonhoc - 1][j]);
}