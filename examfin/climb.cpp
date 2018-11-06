

#include<iostream>
#include<vector>
#include <list>
#include <bits/stdc++.h>
using namespace std;

int h,w;
bool visited[90];
int deg[35][35];
int layer[35][35];
char arr[35][35];
typedef pair<int, int> exPair;
int mindist[90];

void read()
{
    cin >> h >> w;
    for (int i = 0; i < h ; i++){
        for(int j = 0; j < w; j++){
            cin >> arr[i][j];
        } 
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    read();
    // cout << mindist[h+w-2] << "\n";
}