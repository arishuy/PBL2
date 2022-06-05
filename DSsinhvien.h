#ifndef SINHVIEN_H
#define SINHVIEN_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class sinhvien
{
private:
    string mssv, hoten;
    int somonhoc;
    string *mh;

public:
    sinhvien();
    sinhvien(const sinhvien &);
    ~sinhvien();
    void nhap();
    friend istream &operator>>(istream &, sinhvien &);          // đa năng hóa toán tử nhập
    friend ostream &operator<<(ostream &, const sinhvien &);    // đa năng hóa toán tử xuất
    string getMonhoc(int i) const { return mh[i]; };            // xác định môn học vị trí i
    int getSomonhoc() const { return somonhoc; };               // xác định số môn học
    string getMssv() const {return mssv;};
};
typedef class node *Node;
class node
{
private:
    sinhvien data;
    Node next;

public:
    node(sinhvien &data, Node next);
    node(const node &);
    void setData(sinhvien data);         
    sinhvien getData() const;
    void setNext(Node next);
    Node getNext();
    friend class linkedlist;
};
typedef class linkedlist DSsinhvien;
class linkedlist
{
private:
    Node head;
    Node tail;
    int size;

public:
    linkedlist();
    ~linkedlist();
    linkedlist(const linkedlist &);
    void setHead(Node head);
    void setTail(Node tail);                                    // gán
    int getSize() const;                                        // xác định kích thước danh sách
    void createList(ifstream &);                                // tạo danh sách
    friend ostream &operator<<(ostream &, const linkedlist &);  // đa năng hóa toán tử xuất
    Node operator[](int index) const;                           // truy xuất phần tử
    bool check(Node);                                           // kiểm tra mssv có bị trùng hay không
    linkedlist &operator+(sinhvien &);                          // thêm vào cuối danh sách
    linkedlist deleteNode(string mssv);
    int getIndex(string mssv);
    Node SearchNode(string mssv);
    void Search(string mssv);
    void Sort();
};
#endif