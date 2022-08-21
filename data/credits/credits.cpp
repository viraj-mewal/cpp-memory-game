#include <iostream>
#include <windows.h>
#include <conio.h>

#ifndef MACROS_H
#define MACROS_H

#include <unistd.h>

#define msleep(X) usleep(X * 1000)

#endif // MACROS_H

using namespace std;

int main()
{
    string dev = "Developed by : Viraj Mewal";
    string time = "Time Taken : 24 hours";
    string day = "Days Taken : 2 weeks";
    string brain = "Brain Taken : A lot ~_~";

    cout << endl
         << endl;

    cout << "\t\t";

    // dev
    for (int i = 0; i < dev.length(); i++)
    {
        if (dev[i] == 'D')
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        }
        else if (dev[i] == 'V')
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        }

        cout << dev[i];
        usleep(100000);
    }

    cout << endl;
    cout << "\t\t";

    // time
    for (int i = 0; i < time.length(); i++)
    {
        if (time[i] == 'T')
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        }
        else if (time[i] == '2')
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        }

        cout << time[i];
        usleep(100000);
    }

    cout << endl;
    cout << "\t\t";

    // day
    for (int i = 0; i < day.length(); i++)
    {
        if (day[i] == 'D')
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        }
        else if (day[i] == '2')
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        }

        cout << day[i];
        usleep(100000);
    }

    cout << endl;
    cout << "\t\t";

    // brain
    for (int i = 0; i < brain.length(); i++)
    {
        if (brain[i] == 'B')
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        }
        else if (brain[i] == 'A')
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
        }
        else if (brain[i] == '~')
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        }

        cout << brain[i];
        usleep(100000);
    }

    cout << endl
         << endl
         << endl;

    getch();

    system("cls");
    system("main.exe");

    return 0;
}