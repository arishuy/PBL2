#include "XepLich.h"
XepLich::XepLich(){
    n = 0;
}
XepLich::XepLich(DSmonhoc &listMH, DSsinhvien &listSV){
    this->listMH = listMH;
    this->listSV = listSV;
    n = this->listMH.getSize();
    array = new int *[n + 1];                         
    for (int i = 0; i < n + 1; i++)
        array[i] = new int[n + 1];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            array[i][j] = 0;
    cov = new int [n];                               
    for (int i = 0; i < n; i++)
        cov[i] = 0;
}
XepLich::~XepLich(){
    for (int i = 0; i < n; i++)
        delete[] array[i];
    delete[] array;
    delete[] cov;
}
void XepLich::putArray()            
{
    int sv = listSV.getSize();
    for (int i = 0; i < sv; i++)
    {
        int sizeMH = listSV[i]->getData().getSomonhoc();
        for (int j = 0; j < sizeMH; j++)
            for (int k = j + 1; k < sizeMH; k++)
            {
                int num1 = listMH.getIndex(listSV[i]->getData().getMonhoc(j));
                int num2 = listMH.getIndex(listSV[i]->getData().getMonhoc(k));
                array[num1][num2] = array[num2][num1] = 1;
            }
    }
}
void XepLich::showArray(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << array[i][j];
            cout << endl;
        }
}
bool XepLich::check(int color, int i)          
{
    for (int j = 0; j < n; j++)
        if (array[i][j] == 1 && cov[j] == color)
            return false;
    return true;
}
int XepLich::color1(int color)             
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (!cov[i] && check(color, i))
        {
            cov[i] = color;
            count++;
        }
    return count;
}
void XepLich::colorAll()        
{
    int color_number = 0;
    int count = 0;
    while (count < n)
    {
        color_number++;
        count += color1(color_number);
    }
}
void XepLich::setDate(Date &d){
    this->ngaythi = d;
}
void XepLich::print()       
{
    putArray();
    colorAll();
    Date d = ngaythi;
    int n = 0, k = 1;
    while (n < this->n)
    {
        DSmonhoc tmp;
        for (int i = 0; i < this->n; i++)
        {   
            if (cov[i] == k)
            {
                tmp + listMH[i];
                n++;
            }
        }
        buoithi buoi(d, k % 2, tmp);
        cout << buoi;
        if(!(k % 2)) d++;
        k++;
    }
}
void XepLich::write(ofstream &fileout){
    putArray();
    colorAll();
    Date d = ngaythi;
    int n = 0, k = 1;
    while (n < this->n)
    {
        DSmonhoc tmp;
        for (int i = 0; i < this->n; i++)
        {   
            if (cov[i] == k)
            {
                tmp + listMH[i];
                n++;
            }
        }
        buoithi buoi(d, k % 2, tmp);
        fileout << buoi;
        if(!(k % 2)) d++;
        k++;
    }
}