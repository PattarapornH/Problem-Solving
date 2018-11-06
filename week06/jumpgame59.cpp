/*
LANG: C++
TASK: mid59_jumpgame
*/

#include<iostream>
#include<stdio.h>
#define MAX 30
using namespace std;

int jump[MAX][MAX];
int n,k;
bool res = false;
bool reach[MAX][MAX];

void findpath(int r, int c)
{ 
    if(!reach[r][c]){
        // getchar();
        // cout << r << " , " << c;
        reach[r][c] = true;
        int curr = jump[r][c];
        if (r == n && c == n){
            res = true;
        }
        if(r + 1 <= n && jump[r + 1][c] - curr <= k){
            // cout << "down\n";
            findpath(r + 1, c);
        }
        if (r - 1 >= 1 && jump[r - 1][c] - curr <= k){
            // cout << "up\n";
            findpath(r - 1, c);
        }
        if (c + 1 <= n && jump[r][c + 1] - curr <= k){
            // cout << "right\n";
            findpath(r, c + 1);
        }
        if (c - 1 >= 1 && jump[r][c - 1] - curr <= k){
            // cout << "left\n";
            findpath(r, c - 1);
        }
    }
}

main()
{
    cin >> n >> k;
    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < n + 1; j++){
            cin >> jump[i][j];
            reach[i][j] = false;
        }
    }

    findpath(1,1);
    if(res){
        cout << "yes\n";
    }
    else{
        cout << "no\n";
    }
}