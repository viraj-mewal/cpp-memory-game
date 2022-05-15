#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

void back(); // exits the program

int main()
{
    int choice;

    cout << endl
         << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout << "1) Easy" << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << "2) Medium" << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "3) Hard" << endl;
    cout << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
    cout << "4) Back";
    cout << endl
         << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << "Select :- ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        system("cls");
        system("data\\game\\files\\easy\\easy.exe");
        break;

    case 2:
        system("cls");
        system("data\\game\\files\\medium\\medium.exe");
        break;

    case 3:
        system("cls");
        system("data\\game\\files\\hard\\hard.exe");
        break;

    case 4:
        back();
        break;

    default:
        break;
    }
}

void back()
{
    system("cls");
    system("main.exe");
}