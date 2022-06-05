#include "DSsinhvien.h"
#include <iostream>
#include <string>
using namespace std;
node::node(sinhvien &data, Node next)
    : data(data), next(next)
{
}
node::node(const node &n)
    : data(n.data), next(n.next)
{
}
void node::setData(sinhvien data)
{
    this->data = data;
}
sinhvien node::getData() const
{
    return data;
}
void node::setNext(Node next)
{
    this->next = next;
}
Node node::getNext()
{
    return next;
}
linkedlist::linkedlist()
{
    head = NULL;
    tail = NULL;
    size = 0;
}
linkedlist::~linkedlist()
{
    head = NULL;
    tail = NULL;
    size = 0;
}
linkedlist::linkedlist(const linkedlist &l)
{
    this->head = l.head;
    this->tail = l.tail;
    this->size = l.size;
}
void linkedlist::setHead(Node head)
{
    this->head = head;
}
void linkedlist::setTail(Node tail)
{
    this->tail = tail;
}
int linkedlist::getSize() const
{
    return size;
}
ostream &operator<<(ostream &out, const linkedlist &l)
{
    Node tmp = l.head;
    out<<"MSSV\tHo va ten\tMon hoc\n";
    while (tmp != NULL)
    {
        out << tmp->getData();
        tmp = tmp->getNext();
    }
    return out;
}
Node linkedlist::operator[](int index) const
{
    if (index < 0 || index > size)
        return NULL;
    Node tmp = head;
    for (int i = 0; i < index; i++)
        tmp = tmp->getNext();
    return tmp;
}
bool linkedlist::check(Node n){
    for(Node tmp = head ; tmp != NULL; tmp = tmp->getNext()){
        if(tmp->getData().getMssv() == n->getData().getMssv())
            return true;
    }
    return false;
}
linkedlist &linkedlist::operator+(sinhvien &data)
{
    Node tmp = new node(data, NULL);
    if(check(tmp)){
        return *this;
    }
    if (head == NULL)
    {
        head = tail = tmp;
        size = 1;
        return *this;
    }
    tail->setNext(tmp);
    setTail(tmp);
    size++;
    Sort();
    return *this;
}
void linkedlist::createList(ifstream &filein)
{
    while (filein.eof() == false)
    {
        sinhvien data;
        filein >> data;
        *this + data;
    }
}
linkedlist linkedlist::deleteNode(string mssv)
{
    int index = getIndex(mssv);
    Node tmp, tmp2;
    if (index == -1)
    {
        return *this;
    }
    else{
    if (index == 0)
    {
        tmp = head;
        setHead(head->getNext());
        delete tmp;
        size--;
    }
    else if (index == size - 1)
    {
        tmp = head;
        tmp2 = tail;
        for (int i = 0; i < index - 1; i++)
            tmp = tmp->getNext();
        setTail(tmp);
        tmp->setNext(NULL);
        delete tmp2;
        size--;
    }
    else
    {
        tmp = head;
        for (int i = 0; i < index - 1; i++)
            tmp = tmp->getNext();
        tmp2 = tmp->getNext();
        tmp->setNext(tmp2->getNext());
        delete tmp2;
        size--;
    }
    return *this;
    }
}
int linkedlist::getIndex(string mssv)
{
    Node tmp = head;
    for (int i = 0; i < size; i++)
    {
        if (mssv == tmp->getData().getMssv())
            return i;
        tmp = tmp->getNext();
    }
    return -1;
}
Node linkedlist::SearchNode(string mssv){
    Node tmp = head;
    while(tmp != NULL){
        if(tmp->getData().getMssv() == mssv)
            break;
        tmp = tmp->getNext();
    }
    return tmp;
}
void linkedlist::Search(string mssv){
    Node tmp = SearchNode(mssv);
    if(tmp == NULL) cout << "Ma so sinh vien khong ton tai!\n";
    else cout << tmp->getData();
}
void linkedlist::Sort(){
    for(Node tmp = head; tmp != NULL; tmp = tmp->getNext())
        for(Node tmp1 = tmp->getNext(); tmp1 != NULL; tmp1 = tmp1->getNext()){
            if( tmp->getData().getMssv() > tmp1->getData().getMssv()){
                sinhvien tmp2 = tmp->getData();
                tmp->setData(tmp1->getData());
                tmp1->setData(tmp2);
            }
        }
}