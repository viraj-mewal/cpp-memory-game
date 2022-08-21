#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

int main()
{
    // priting rules

    ifstream is("data\\rules\\rules.txt");
    string line;
    bool isPrinted = false;

    while (getline(is, line))
    {
        cout << line << endl;
        isPrinted = true;
    }

    if (isPrinted)
    {
        getch();
    }
    else
    {
        return 0;
    }

    // get back to main menu

    system("cls");
    system("main.exe");

    return 0;
}