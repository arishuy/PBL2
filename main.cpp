#include "Menu.h"
using namespace std;

int main()
{
    FILE * fp = NULL;
    fp = fopen("name.txt", "r");
    char a;
    {
        textcolor(12);
        while ((a = fgetc(fp)) != EOF)
        {   
        cout << a;
        }
    }
    fclose(fp);
    Menu();
		XuliMenu();
    return 0;
}