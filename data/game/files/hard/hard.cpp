// memory game - easy

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

using namespace std;

vector<int> nums;

bool isFirst[10] = {false, false, false, false, false, false, false, false, false, false};
bool isSecond[10] = {false, false, false, false, false, false, false, false, false, false};

int temp_no = 0;

int arr[4][5] = // arr[col][row]
    {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
};

int arr_show[4][5] = // arr[col][row]
    {
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, false, false, false, false},
};

// winning variables

int attempts = 0;        // every 2 flips
int shuffleAttempts = 0; // shuffle affter every 5 wrong attempts
int heart = 1;           // by default 1 heart (hard mode)

int firstFlip = 100;
int lastFlip = 100;

int firstShow[2] = {200, 200};
int lastShow[2] = {200, 200};

void arrange();            // sets the int arr randomly
void board();              // prints the board
int getRandNo();           // sends a random number from nums vector array
bool checkMatch();         // check for a match
int openValue(int choice); // inserts value in the arr
void checkAndHide();       // checks for match otherwise hide that
bool checkWin();           // check for the win
void greet();              // greet after win
void showAnswers();        // reveals the board with answers

int main()
{
    srand(time(0));

    arrange();
    // game loop
    do
    {
        if (shuffleAttempts == 5)
        {
            for (int i = 0; i <= 10; i++)
            {
                isFirst[i] = false;
                isSecond[i] = false;
            }
            arrange();
            shuffleAttempts = 0;
        }
        board();
        int choice;

        cout << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "Attempts :- " << attempts << endl;
        cout << "Hearts :- " << heart << endl;

        cout << endl;

        // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout << "Enter your choice (1 - 20) (0 - heart) (any key - exit) :- ";
        try
        {
            cin >> choice;

            // check if any other character is typed

            if (cin.fail())
            {
                char isExit;
                cin.clear();
                cin.ignore();
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                cout << "Do yo really want to exit (y/n) :- ";
                cin >> isExit;
                if (isExit == 'y')
                {
                    system("cls");
                    system("main.exe");
                }
                else
                {
                    continue;
                }
                sleep(2);
                continue;
            }

            if (choice == 0)
            {
                if (heart)
                {
                    showAnswers();
                    heart--;
                    continue;
                }
                else
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    cout << endl;
                    cout << "You have 0 heart to use....." << endl;
                    sleep(2);
                    continue;
                }
            }
            if (choice > 20 or choice < 1)
            {
                throw(choice);
            }
            int got = openValue(choice);
            if (got)
            {
                throw 1;
            }
        }
        catch (int n)
        {
            if (n)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                cout << "Invalid choice ! box is already open.";
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                cout << "Invalid choice ! Enter number between 1 - 20 to select the appropriate box.";
            }
            sleep(2);
            continue;
        }
        if (checkMatch())
        {
            if (checkWin())
            {
                break;
            }
            continue;
        }
    } while (true);

    greet();
    return 0;
}

void showAnswers()
{
    system("cls");
    cout << endl
         << "Here are the answers - don't tell anyone else !" << endl;

    cout << endl;
    cout << "One heart used !" << endl
         << endl;
    for (int col = 0; col < 4; col++)
    {
        if (col == 0)
        {
            for (int i = 0; i < 5; i++)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                if (i == 0)
                {
                    cout << " ___ ";
                }
                else
                {
                    cout << "___ ";
                }
            }
            cout << endl;
        }
        for (int row = 0; row < 5; row++)
        {
            if (row == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                cout << "| ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                cout << arr[col][row];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                cout << " |";
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                cout << " ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                cout << arr[col][row];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                cout << " |";
            }
        }
        cout << endl;

        // draw the slating lines

        for (int i = 0; i < 5; i++)
        {
            if (i == 0)
            {
                cout << " ___ ";
            }
            else
            {
                cout << "___ ";
            }
        }
        cout << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << "\n\nAnswers will hide after 5s....";
    sleep(5);
}

void greet()
{
    system("cls");

    board();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout << endl
         << endl
         << "Congratulations you win" << endl;
}

bool checkWin()
{
    bool win = true;
    bool breakthis = false;
    for (int col = 0; col < 4; col++)
    {
        for (int row = 0; row < 5; row++)
        {
            if (not(arr_show[col][row]))
            {
                win = false;
                breakthis = true;
                break;
            }
            else
            {
                win = true;
            }
        }
        if (breakthis)
        {
            break;
        }
    }

    if (win)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void checkAndHide()
{
    board();

    int noMatch[2] = {0, 0};
    int i = 0;

    for (int i = 0; i < 2; i++)
    {
        firstShow[i] = 200;
        lastShow[i] = 200;
    }

    attempts++;
    shuffleAttempts++;

    sleep(1.5);
}

int openValue(int choice)
{
    if (not(firstFlip == 100) and not(lastFlip == 100))
    {
        firstFlip = 100;
        lastFlip = 100;
    }

    int i = 1;
    bool breakthis = false;

    for (int col = 0; col < 4; col++)
    {
        for (int row = 0; row < 5; row++)
        {
            if (i == choice)
            {
                if (not arr_show[col][row] and not(firstShow[0] == col and firstShow[1] == row))
                {
                    if (firstShow[0] == 200 and firstShow[1] == 200)
                    {
                        firstShow[0] = col;
                        firstShow[1] = row;
                    }
                    else
                    {
                        lastShow[0] = col;
                        lastShow[1] = row;
                    }
                    if (firstFlip == 100)
                    {
                        firstFlip = arr[col][row];
                    }
                    else if (lastFlip == 100)
                    {
                        lastFlip = arr[col][row];
                    }
                }
                else
                {
                    return 1;
                }
                breakthis = true;
                break;
            }
            i++;
        }
        if (breakthis)
        {
            break;
        }
    }

    if (not(firstFlip == lastFlip) and not(firstFlip == 100) and not(lastFlip == 100))
    {
        cout << "checking for hide";
        checkAndHide();
    }

    return 0;
}

int getRandNo()
{
    temp_no = rand() % 10;

    if (not(isFirst[temp_no]))
    {
        temp_no = nums[temp_no];
        isFirst[temp_no] = true;
    }
    else if (not(isSecond[temp_no]))
    {
        temp_no = nums[temp_no];
        isSecond[temp_no] = true;
    }
    else
    {
        temp_no = getRandNo();
    }

    return temp_no;
}

void arrange()
{

    // fill the nums

    for (int i = 0; i < 10; i++)
    {
        nums.push_back(i);
    }

    for (int col = 0; col < 4; col++)
    {
        for (int row = 0; row < 5; row++)
        {
            arr[col][row] = getRandNo();
        }
    }
}

bool checkMatch()
{
    if (firstFlip == lastFlip)
    {
        if (not(firstFlip))
        {
            heart++;
        }
        attempts++;
        for (int col = 0; col < 4; col++)
        {
            for (int row = 0; row < 5; row++)
            {
                if (arr[col][row] == firstFlip)
                {
                    arr_show[col][row] = true;
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

void board()
{
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << "********* Welcome To Memory Game - hard (Developed by Viraj Mewal ) *********" << endl
         << endl
         << endl;

    for (int col = 0; col < 4; col++)
    {
        if (col == 0)
        {
            for (int i = 0; i < 5; i++)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                if (i == 0)
                {
                    cout << " ___ ";
                }
                else
                {
                    cout << "___ ";
                }
            }
            cout << endl;
        }
        for (int row = 0; row < 5; row++)
        {
            if (row == 0)
            {
                if (((col == firstShow[0]) and (row == firstShow[1])) or (arr_show[col][row]))
                {
                    cout << "| ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                    cout << arr[col][row];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                    cout << " |";
                }
                else if (((col == lastShow[0]) and (row == lastShow[1])) or (arr_show[col][row]))
                {
                    cout << "| ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                    cout << arr[col][row];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                    cout << " |";
                }
                else
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                    cout << "| ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                    cout << "*";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                    cout << " |";
                }
            }
            else
            {
                if (((col == firstShow[0]) and (row == firstShow[1])) or (arr_show[col][row]))
                {
                    cout << " ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                    cout << arr[col][row];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                    cout << " |";
                }
                else if (((col == lastShow[0]) and (row == lastShow[1])) or (arr_show[col][row]))
                {
                    cout << " ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                    cout << arr[col][row];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                    cout << " |";
                }
                else
                {
                    cout << " ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                    cout << "*";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                    cout << " |";
                }
            }
        }
        cout << endl;

        // draw the slating lines

        for (int i = 0; i < 5; i++)
        {
            if (i == 0)
            {
                cout << " ___ ";
            }
            else
            {
                cout << "___ ";
            }
        }
        cout << endl;
    }
}