#include "DSsinhvien.h"
#include "DSmonhoc.h"
#include "buoithi.h"
#include "Date.h"
#include "XepLich.h"
#include <iostream>
#include <fstream>
#include "DoHoa.h"
using namespace std;
void Menu()
{
    inmau("Cac lua chon:", 3); cout << endl;
    inmau("1. Xuat ra man hinh",5); cout << endl;
    // cout << "Cac lua chon:" << endl;
    // cout << "1. Xuat ra man hinh" << endl;
    cout << "2. Xuat ra file" << endl;
    cout << "3. Them sinh vien" << endl;
    cout << "4. Xoa sinh vien" << endl;
    cout << "5. In danh sach sinh vien" << endl;
    cout << "6. Tim kiem sinh vien" << endl;
    cout << "7. Xoa man hinh" << endl;
    cout << "8. Thoat"<< endl;
}
int ChonMenu()
{
    int n = 0;
	inmau("Nhap lua chon : ", 9);
	cin >> n;
	if (n > 0 || n < 9)
		return n;
	else return ChonMenu();
}
void XuliMenu()
{
    ifstream filein;
    ofstream fileout;
    DSsinhvien listSV;
    DSmonhoc listMH;
    filein.open("monhoc.txt", ios_base::in);
    listMH.createList(filein);
    filein.close();
    filein.open("sinhvien.txt", ios_base::in);
    listSV.createList(filein);
    filein.close();
    while(1){
    int chon = ChonMenu();
    switch (chon)
    {
    case 1:
        {
        textcolor(4);
        XepLich lich(listMH, listSV);
        Date d;
        cout << "Nhap ngay bat dau thi\n";
        cin >> d;
        lich.setDate(d);
        lich.print();
        break;
        }
    case 2:
        {
        textcolor(6);
        XepLich lich(listMH, listSV);
        Date d;
        cout << "Nhap ngay bat dau thi\n";
        cin >> d;
        lich.setDate(d);
        fileout.open("output.txt", ios_base::out);
        lich.write(fileout);
        fileout.close();
        break;
        }
    case 3 :
        {
        textcolor(12);
        sinhvien sv;
        int n = listSV.getSize();
        sv.nhap();
        listSV+sv;
        if(n == listSV.getSize()) cout << "Ma so sinh vien da ton tai!\n";
        else cout << "Them thanh cong!\n";
        break;
        }
    case 4:
        {
        textcolor(12);
        cout << "Nhap ma so sinh vien muon xoa: ";
        string s;
        cin >> s;
        int n = listSV.getSize();
        listSV.deleteNode(s);
        if(n == listSV.getSize()) cout << "Ma so sinh vien khong ton tai!\n";
        else cout << "Xoa thanh cong!\n";
        break;
        }
    case 5:
        textcolor(12);
        cout << listSV;
        break;
    case 6:
        {
        textcolor(12);
        string mssv;
        cout << "Nhap ma so sinh vien can tim: "; cin >> mssv;
        listSV.Search(mssv);
        break;
        }
    case 7:
        system("cls");
        Menu();
        break;
    case 8:
        textcolor(7);
        cout << "End." << endl;
        exit(1);
        break;
    }
    }
}