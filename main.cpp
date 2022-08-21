#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

void exit(); // exits the program

int main(){
    system("cls");
    int choice;

    cout << endl
         << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout << "1) Start Game" << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << "2) Show Rules" << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << "3) Credits" << endl;
    cout << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "4) Exit";
    cout << endl
         << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << "Select :- ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        system("cls");
        system("data\\game\\game.exe");
        break;

    case 2:
        system("cls");
        system("data\\rules\\rules.exe");
        break;

    case 3:
        system("cls");
        system("data\\credits\\credits.exe");   
        break;

    case 4:
        exit();
        break;

    default:
        break;
    }
    return 0;
}

void exit()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    cout << endl
         << "Bye :)" << endl;
    sleep(2);
}