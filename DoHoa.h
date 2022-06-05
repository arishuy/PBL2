#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

// Hàm thay đổi kích cỡ của khung cmd với tham số truyền vào là chiều cao, chiều rộng.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void inmau(string s,int x)
{
  textcolor(x);
  cout << s;
}
// Hàm dịch chuyển con trỏ đến tọa độ x, y.
// void gotoxy(int x,int y)
// {    
// 	HANDLE hConsoleOutput;    
// 	COORD Cursor_an_Pos = {x-1,y-1};   
// 	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
// 	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
// }

// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

// Hàm lấy Key từ bàn phím
/* GetAsyncKeyState(VK_ESCAPE) => bắt sự kiện phím Esc */ 

// Hàm tự viết
// void ToMau(int x, int y, char *a, int color) // x, y là tọa độ con trỏ cần nhảy đến để viết, a là chuỗi cần truyền vào, color là màu truyền vào.
// {
// 	gotoxy(x, y);
// 	textcolor(color);
// 	cout << a;
// 	textcolor(7);
// }