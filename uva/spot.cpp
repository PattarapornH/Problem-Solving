/*
LANG: C++
TASK: uva10703_freespots
*/

#include<iostream>
using namespace std;

int n,w,h;
int x1,y1,x2,y2;
bool spot[510][510];

void init()
{
    for(int i=0; i<510; i++){
        for(int j=0; j<510; j++){
            spot[i][j] = false;
        }
    }
}

void swap(int* a,int* b)
{
    if(*a > *b){
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

void count_spot(int* cnt)
{
    for(int i=x1; i<=x2; i++){
        for(int j=y1; j<=y2; j++){
            if(!spot[i][j]){
                spot[i][j] = true;
                (*cnt)--;
            }
        }
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        cin >> w >> h >> n;
        if(w == 0 && h == 0 && n == 0){
            break;
        }
        init();
        int cnt = w * h;
        for (int i = 0; i < n; i++){
            cin >> x1 >> y1 >> x2 >> y2;
            swap(&x1,&x2);
            swap(&y1,&y2);
            count_spot(&cnt);
            // cout << "----------\n";
            // cout << x1 << " " << x2 << " " << y1 << " " << y2 << "\n";
        }
        if(cnt == 0){
            cout << "There is no empty spots.";
        }
        else if(cnt == 1){
            cout << "There is one empty spot.";
        }
        else{
            cout << "There are " << cnt << " empty spots.";
        }
        cout << "\n";
    }
}