#include <iostream>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

using namespace std;

vector<int> nums;

vector<bool> isFirst = {false, false, false, false, false, false, false, false, false, false};
vector<bool> isSecond = {false, false, false, false, false, false, false, false, false, false};

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

int attempts = 0;

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

int main()
{
    arrange();
    // game loop
    do
    {
        board();
        int choice;

        cout << endl;
        cout << endl;
        cout << "first flip :- " << firstFlip << endl;
        cout << "Last flip :- " << lastFlip << endl;

        cout << endl;

        cout << "Enter your choice (1 - 20) :- ";

        try
        {
            cin >> choice;
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
                cout << "Invalid choice ! box is already open.";
            }
            else
            {
                cout << "Invalid choice ! Enter number between 1 - 20 to select the appropriate box.";
            }
            sleep(1);
            continue;
        }
        if (checkMatch())
        {
            continue;
        }
    } while (true);
    return 0;
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

    
}

int openValue(int choice)
{
    if (not(firstFlip == 100) and not(lastFlip == 100))
    {
        firstFlip = 100;
        lastFlip = 100;
    }

    switch (choice)
    {
    case 1:
        if (not arr_show[0][0])
        {
            if (firstShow[0] == 200 and firstShow[1] == 200)
            {
                firstShow[0] = 0;
                firstShow[1] = 0;
            }
            else
            {
                lastShow[0] = 0;
                lastShow[1] = 0;
            }
            if (firstFlip == 100)
            {
                firstFlip = arr[0][0];
            }
            else if (lastFlip == 100)
            {
                lastFlip = arr[0][0];
            }
        }
        else
        {
            return 1;
        }
        break;

    case 2:
        if (not arr_show[0][1])
        {
            if (firstShow[0] == 200 and firstShow[1] == 200)
            {
                firstShow[0] = 0;
                firstShow[1] = 1;
            }
            else
            {
                lastShow[0] = 0;
                lastShow[1] = 1;
            }
            if (firstFlip == 100)
            {
                firstFlip = arr[0][1];
            }
            else if (lastFlip == 100)
            {
                lastFlip = arr[0][1];
            }
        }
        else
        {
            return 1;
        }
        break;

    case 3:
        if (not arr_show[0][2])
        {
            if (firstShow[0] == 200 and firstShow[1] == 200)
            {
                firstShow[0] = 0;
                firstShow[1] = 2;
            }
            else
            {
                lastShow[0] = 0;
                lastShow[1] = 2;
            }
            if (firstFlip == 100)
            {
                firstFlip = arr[0][2];
            }
            else if (lastFlip == 100)
            {
                lastFlip = arr[0][2];
            }
        }
        else
        {
            return 1;
        }
        break;

    case 4:
        if (not arr_show[0][3])
        {
            if (firstShow[0] == 200 and firstShow[1] == 200)
            {
                firstShow[0] = 0;
                firstShow[1] = 3;
            }
            else
            {
                lastShow[0] = 0;
                lastShow[1] = 3;
            }
            if (firstFlip == 100)
            {
                firstFlip = arr[0][3];
            }
            else if (lastFlip == 100)
            {
                lastFlip = arr[0][3];
            }
        }
        else
        {
            return 1;
        }
        break;

    case 5:
        if (not arr_show[0][4])
        {
            if (firstShow[0] == 200 and firstShow[1] == 200)
            {
                firstShow[0] = 0;
                firstShow[1] = 4;
            }
            else
            {
                lastShow[0] = 0;
                lastShow[1] = 4;
            }
            if (firstFlip == 100)
            {
                firstFlip = arr[0][4];
            }
            else if (lastFlip == 100)
            {
                lastFlip = arr[0][4];
            }
            sleep(1);
        }
        else
        {
            return 1;
        }
        break;

    case 6:
        if (not arr_show[1][0])
        {
            if (firstShow[0] == 200 and firstShow[1] == 200)
            {
                firstShow[0] = 1;
                firstShow[1] = 0;
            }
            else
            {
                lastShow[0] = 1;
                lastShow[1] = 0;
            }
            if (firstFlip == 100)
            {
                firstFlip = arr[1][0];
            }
            else if (lastFlip == 100)
            {
                lastFlip = arr[1][0];
            }
        }
        else
        {
            return 1;
        }
        break;

    case 7:
        if (not arr_show[1][1])
        {
            if (firstShow[0] == 200 and firstShow[1] == 200)
            {
                firstShow[0] = 1;
                firstShow[1] = 1;
            }
            else
            {
                lastShow[0] = 1;
                lastShow[1] = 1;
            }
            if (firstFlip == 100)
            {
                firstFlip = arr[1][1];
            }
            else if (lastFlip == 100)
            {
                lastFlip = arr[1][1];
            }
        }
        else
        {
            return 1;
        }
        break;

    case 8:
        if (not arr_show[1][2])
        {
            if (firstShow[0] == 200 and firstShow[1] == 200)
            {
                firstShow[0] = 1;
                firstShow[1] = 2;
            }
            else
            {
                lastShow[0] = 1;
                lastShow[1] = 2;
            }
            if (firstFlip == 100)
            {
                firstFlip = arr[1][2];
            }
            else if (lastFlip == 100)
            {
                lastFlip = arr[1][2];
            }
        }
        else
        {
            return 1;
        }
        break;

    case 9:
        if (not arr_show[1][3])
        {
            if (firstShow[0] == 200 and firstShow[1] == 200)
            {
                firstShow[0] = 1;
                firstShow[1] = 3;
            }
            else
            {
                lastShow[0] = 1;
                lastShow[1] = 3;
            }
            if (firstFlip == 100)
            {
                firstFlip = arr[1][3];
            }
            else if (lastFlip == 100)
            {
                lastFlip = arr[1][3];
            }
        }
        else
        {
            return 1;
        }
        break;

    case 10:
        if (not arr_show[1][4])
        {
            if (firstShow[0] == 200 and firstShow[1] == 200)
            {
                firstShow[0] = 1;
                firstShow[1] = 4;
            }
            else
            {
                lastShow[0] = 1;
                lastShow[1] = 4;
            }
            if (firstFlip == 100)
            {
                firstFlip = arr[1][4];
            }
            else if (lastFlip == 100)
            {
                lastFlip = arr[1][4];
            }
        }
        else
        {
            return 1;
        }
        break;

    case 11:
        if (not arr_show[2][0])
        {
            if (firstShow[0] == 200 and firstShow[1] == 200)
            {
                firstShow[0] = 2;
                firstShow[1] = 0;
            }
            else
            {
                lastShow[0] = 2;
                lastShow[1] = 0;
            }
            if (firstFlip == 100)
            {
                firstFlip = arr[2][0];
            }
            else if (lastFlip == 100)
            {
                lastFlip = arr[2][0];
            }
        }
        else
        {
            return 1;
        }
        break;

    case 12:
        if (not arr_show[2][1])
        {
            if (firstShow[0] == 200 and firstShow[1] == 200)
            {
                firstShow[0] = 2;
                firstShow[1] = 1;
            }
            else
            {
                lastShow[0] = 2;
                lastShow[1] = 1;
            }
            if (firstFlip == 100)
            {
                firstFlip = arr[2][1];
            }
            else if (lastFlip == 100)
            {
                lastFlip = arr[2][1];
            }
        }
        else
        {
            return 1;
        }
        break;

    case 13:
        if (not arr_show[2][2])
        {
            if (firstShow[0] == 200 and firstShow[1] == 200)
            {
                firstShow[0] = 2;
                firstShow[1] = 2;
            }
            else
            {
                lastShow[0] = 2;
                lastShow[1] = 2;
            }
            if (firstFlip == 100)
            {
                firstFlip = arr[2][2];
            }
            else if (lastFlip == 100)
            {
                lastFlip = arr[2][2];
            }
        }
        else
        {
            return 1;
        }
        break;

    case 14:
        if (not arr_show[2][3])
        {
            if (firstShow[0] == 200 and firstShow[1] == 200)
            {
                firstShow[0] = 2;
                firstShow[1] = 3;
            }
            else
            {
                lastShow[0] = 2;
                lastShow[1] = 3;
            }
            if (firstFlip == 100)
            {
                firstFlip = arr[2][3];
            }
            else if (lastFlip == 100)
            {
                lastFlip = arr[2][3];
            }
        }
        else
        {
            return 1;
        }
        break;

    case 15:
        if (not arr_show[2][4])
        {
            if (firstShow[0] == 200 and firstShow[1] == 200)
            {
                firstShow[0] = 2;
                firstShow[1] = 4;
            }
            else
            {
                lastShow[0] = 2;
                lastShow[1] = 4;
            }
            if (firstFlip == 100)
            {
                firstFlip = arr[2][4];
            }
            else if (lastFlip == 100)
            {
                lastFlip = arr[2][4];
            }
        }
        else
        {
            return 1;
        }
        break;

    case 16:
        if (not arr_show[3][0])
        {
            if (firstShow[0] == 200 and firstShow[1] == 200)
            {
                firstShow[0] = 3;
                firstShow[1] = 0;
            }
            else
            {
                lastShow[0] = 3;
                lastShow[1] = 0;
            }
            if (firstFlip == 100)
            {
                firstFlip = arr[3][0];
            }
            else if (lastFlip == 100)
            {
                lastFlip = arr[3][0];
            }
        }
        else
        {
            return 1;
        }
        break;

    case 17:
        if (not arr_show[3][1])
        {
            if (firstShow[0] == 200 and firstShow[1] == 200)
            {
                firstShow[0] = 3;
                firstShow[1] = 1;
            }
            else
            {
                lastShow[0] = 3;
                lastShow[1] = 1;
            }
            if (firstFlip == 100)
            {
                firstFlip = arr[3][1];
            }
            else if (lastFlip == 100)
            {
                lastFlip = arr[3][1];
            }
        }
        else
        {
            return 1;
        }
        break;

    case 18:
        if (not arr_show[3][2])
        {
            if (firstShow[0] == 200 and firstShow[1] == 200)
            {
                firstShow[0] = 3;
                firstShow[1] = 2;
            }
            else
            {
                lastShow[0] = 3;
                lastShow[1] = 2;
            }
            if (firstFlip == 100)
            {
                firstFlip = arr[3][2];
            }
            else if (lastFlip == 100)
            {
                lastFlip = arr[3][2];
            }
        }
        else
        {
            return 1;
        }
        break;

    case 19:
        if (not arr_show[3][3])
        {
            if (firstShow[0] == 200 and firstShow[1] == 200)
            {
                firstShow[0] = 3;
                firstShow[1] = 3;
            }
            else
            {
                lastShow[0] = 3;
                lastShow[1] = 3;
            }
            if (firstFlip == 100)
            {
                firstFlip = arr[3][3];
            }
            else if (lastFlip == 100)
            {
                lastFlip = arr[3][3];
            }
        }
        else
        {
            return 1;
        }
        break;

    case 20:
        if (not arr_show[3][4])
        {
            if (firstShow[0] == 200 and firstShow[1] == 200)
            {
                firstShow[0] = 3;
                firstShow[1] = 4;
            }
            else
            {
                lastShow[0] = 3;
                lastShow[1] = 4;
            }
            if (firstFlip == 100)
            {
                firstFlip = arr[3][4];
            }
            else if (lastFlip == 100)
            {
                lastFlip = arr[3][4];
            }
        }
        else
        {
            return 1;
        }
        break;

    default:
        break;
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
    temp_no = rand() % 10 + 1;

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

    cout << "********* Welcome To Memory Game (Developed by Viraj Mewal ) *********" << endl
         << endl
         << endl;

    for (int col = 0; col < 4; col++)
    {
        if (col == 0)
        {
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
        for (int row = 0; row < 5; row++)
        {
            if (row == 0)
            {
                if (((col == firstShow[0]) and (row == firstShow[1])) or (arr_show[col][row]))
                {
                    cout << "| " << arr[col][row] << " |";
                }
                else if (((col == lastShow[0]) and (row == lastShow[1])) or (arr_show[col][row]))
                {
                    cout << "| " << arr[col][row] << " |";
                }
                else
                {
                    cout << "| * |";
                }
            }
            else
            {
                if (((col == firstShow[0]) and (row == firstShow[1])) or (arr_show[col][row]))
                {
                    cout << " " << arr[col][row] << " |";
                }
                else if (((col == lastShow[0]) and (row == lastShow[1])) or (arr_show[col][row]))
                {
                    cout << " " << arr[col][row] << " |";
                }
                else
                {
                    cout << " * |";
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