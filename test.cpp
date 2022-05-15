#include <iostream>
#include <filesystem>
#include <string>
#include <unistd.h>
using namespace std;

int main()
{

    int arr[6][7] = {                        // 1 - X, 2 - O (downward - column, sideward - row)
                     {0, 0, 0, 0, 0, 0, 0},  // 0
                     {0, 0, 0, 0, 0, 0, 0},  // 1
                     {0, 0, 0, 0, 0, 0, 0},  // 2
                     {0, 0, 0, 0, 0, 5, 0},  // 3
                     {0, 0, 0, 0, 0, 0, 0},  // 4
                     {0, 0, 0, 0, 0, 0, 0}}; // 5

    // for (int col = 0; col < 4; col++)
    // {
    //     for (int row = 0; row < 5; row++)
    //     {
    //         if (i == choice)
    //         {
    //             if (not arr_show[col][row])
    //             {
    //                 if (firstShow[0] == 200 and firstShow[1] == 200)
    //                 {
    //                     firstShow[0] = 0;
    //                     firstShow[1] = 0;
    //                 }
    //                 else
    //                 {
    //                     lastShow[0] = 0;
    //                     lastShow[1] = 0;
    //                 }
    //                 if (firstFlip == 100)
    //                 {
    //                     firstFlip = arr[col][row];
    //                 }
    //                 else if (lastFlip == 100)
    //                 {
    //                     lastFlip = arr[col][row];
    //                 }
    //             }
    //             else
    //             {
    //                 return 1;
    //             }
    //             breakthis = true;
    //             break;
    //         }
    //         i++;
    //     }
    //     if (breakthis)
    //     {
    //         break;
    //     }
    // }

    char path[256];
    getcwd(path, 256);
    cout << endl << path << endl;
    return 0;
}