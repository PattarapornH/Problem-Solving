/*
LANG: C++
TASK: box
*/

#include <iostream>
#include <vector>
#include<cstring>

using namespace std;

char field[32][32];
int n, k;
int newmap[30][30];

void read()
{
    cin >> n >> k;
    string txt;
    for(int i=0; i<n; i++){
        cin >> txt;
        for(int j=0; j<k; j++){
            field[i][j] = txt[j];
        }
    }
}

void init()
{
    for(int i=0 ;i<n ;i++){
        for(int j=0; j<k; j++){
            newmap[i][j] = 0;
        }
    }
}
void findpath(int row, int col)
{
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<k; j++){
    //         if(field[i][j] == '.'){
    //             newmap[i][j] = 1;
    //         }
    //     }
    // }
    if (field[row][col] != '#')
    {
        newmap[row][col] = 1;
    }

    if (row + 1 <= n && field[row + 1][col] != '#')
    {
        findpath(row+1, col);
    }
    if (row - 1 >= 1 && field[row - 1][col] != '#')
    {
        findpath(row-1, col);
    }
    if (col + 1 <= k && field[row][col + 1] != '#')
    {
        findpath(row, col+1);
    }
    if (col - 1 >= 1 && field[row][col - 1] != '#')
    {
        findpath(row, col-1);
    }
}

// void create_newmap()
// {
//     for(int i=0; i<n-2; i++){
//         for(int j=0; j<k-2; ){
//             if(field[i][j] == '#'){
//                 j+=2;
//                 continue;
//             }
//             if(field[i+1][j] == '.' && field[i][j+1] == '.' && field[i+1][j+1] == '.'){
//                 newmap[i][j] = 1;
//             //    i++;
//             //   j++;
//             }
//             j++;
            
//         }
//     }
// }

main()
{
    read();
    init();
    findpath(0,0);
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            cout << newmap[i][j];
        }
        cout << endl;
    }
}

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= k; j++)
    //     {
    //         if (field[i][j] != '#')
    //         {
    //             checkpath(j, i);
    //             if (check1 && !check2)
    //             {
    //                 res[1] += count;
    //             }
    //             if (check2 && !check1)
    //             {
    //                 res[1] += count;
    //             }
    //             if (check1 && check2)
    //             {
    //                 res[0] += count;
    //             }
    //             if (!check1 && !check2)
    //                 res[2] += count;

    //             count = 0;
    //             check1 = false;
    //             check2 = false;
    //         }
    //     }
    // }
    //cout << count << endl;
    // cout << res[0] << " " << res[1];
// }