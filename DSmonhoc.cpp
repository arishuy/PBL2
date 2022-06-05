#include "DSmonhoc.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
monhoc::monhoc()
{
    ten = "";
    msmh = "";
}
monhoc::~monhoc()
{
}
monhoc::monhoc(const monhoc &data)
{
    this->msmh = data.msmh;
    this->ten = data.ten;
}
istream &operator>>(istream &in, monhoc &data)
{
    getline(in, data.msmh, '-');
    getline(in, data.ten);
    for(int i = 0; i < data.ten.length(); i++)
        data.ten[i] = toupper(data.ten[i]);
    return in;
}
ostream &operator<<(ostream &out, const monhoc &data)
{
    out << data.msmh << "-" << data.ten;
    return out;
}
List::List(int size) : size(size)
{
    data = new monhoc[size];
}
List::List(const List &l){
    this->size = l.size;
    this->data = new monhoc[size];
    for(int i = 0; i < size; i++)
        this->data[i] = l[i]; 
}
List::~List()
{
    delete[] data;
}
void doiSize(List &l, int oldsize, int newsize)
{
    monhoc *tmp = new monhoc[oldsize];
    for (int i = 0; i < oldsize; i++)
        tmp[i] = l[i];
    delete[] l.data;
    l.data = new monhoc[newsize];
    int Min = (oldsize < newsize) ? oldsize : newsize;
    for (int i = 0; i < Min; i++)
        l[i] = tmp[i];
    delete[] tmp;
}
List &List::operator+(monhoc &data)
{
    int oldsize = size;
    int newsize = ++size;
    doiSize(*this, oldsize, newsize);
    this->data[newsize - 1] = data;
    return *this;
}
void List::createList(ifstream &filein)
{
    monhoc data;
    while (filein.eof() == false)
    {
        filein >> data;
        *this + data;
    }
}
ostream &operator<<(ostream &out, const List &l)
{
    for (int i = 0; i < l.size; i++)
    {
        out << l.data[i] << endl;
    }
    return out;
}
int List::getIndex(string s) const
{
    for (int i = 0; i < size; i++)
        if (s == data[i].getten())
            return i;
    return size;
}