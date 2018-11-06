/*
LANG: C++
TASK: box
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

char field[32][32];
int n, k;

void read()
{
    cin >> n >> k;
    string txt;
    for (int i = 1; i <= n; i++)
    {
        cin >> txt;
        for (int j = 1; j <= k; j++)
        {
            field[i][j] = txt[j];
        }
    }
}

int newmap[30][30];
bool visited[30][30];

void init()
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            newmap[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

void create_newmap()
{
    for(int i=1; i<=n-1; i++){
        for(int j=1; j<=k-1; j++){
            if(field[i+1][j] == '.' && field[i][j+1] == '.' && field[i+1][j+1] == '.' && field[i][j] == '.'){
                newmap[i][j] = 1;
            }
        }
    }
}

const int dir[][2] = {
    { -1, 0 },
    { 1, 0 },
    { 0, -1 },
    { 0, 1 }
};

bool findpath(int col, int row)
{
    //getchar();
    if (row == n - 1) {
        return true;
    }

    for (int i = 0; i < 4; i++) {
        int nc = col + dir[i][0];
        int nr = row + dir[i][1];
        if (newmap[nr][nc] == 1) {
      //      printf("search: %d %d\n", nc, nr);
            newmap[nr][nc] = 0;
            bool found = findpath(nc, nr);
            if (found) {
                return true;
            }
            newmap[nr][nc] = 1;
        }
    }

    return false;
}

int main()
{
    read();
    init();
    create_newmap();
    //cout << "----------------------\n";
    /*for(int i=1; i<=n-1; i++){
     for(int j=1; j<=k-1; j++){*/
         //    cout << newmap[i][j] ;
       //  }
     //    cout << endl;
   //  }
 //   cout << "----------------------\n";

    // for (int i = 0; i < n - 1; i++)
    // {
        for (int j = 1; j <= k-1; j++)
        {
            if (newmap[1][j] == 1)
            {
                if(findpath(j, 1)){
                    cout << "yes" << endl;
                    return 0;
                }
                // else{
                //     cout << "no" << endl;
                //     return 0;
                // }
            }
        }
        cout << "no" << endl;
    // }

}