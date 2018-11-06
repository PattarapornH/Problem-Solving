/*
LANG: C++
TASK: uva10502_cntrect
*/

#include<iostream>
using namespace std;

#define MAX 110

int r,c;
int cnt = 0;
char sq[MAX][MAX];

int count_rect()
{
    cnt = 0;
    int x,y,test;
    for(int i=0; i < r; i++){
        int tmp[MAX] = {};
        for (int j = i; j < r; j++){
            for(int k = 0; k < c; k++){
                tmp[k] += sq[j][k] - '0';
                if (k == 0 || test != x * y){
                    test = 0,x = 0;
                }
                test += tmp[k];
                x++;
                y = j-i+1;
                if(test == x*y){
                    cnt+=x;
                }
            }
        }
    }
    return cnt;
}

main()
{
    while(true){
        cin >> r;
        /*------------*/
        if(r == 0){
            break;
        }
        /*------------*/
        cin >> c;
        for(int i=0; i<r; i++){
            cin >> sq[i];
        }
        cout << count_rect() << "\n";
    }
}
