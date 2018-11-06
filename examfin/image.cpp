
#include<iostream>
#include<cstdlib>
using namespace std;

int l,h,r;
int map[110][110];
int con[110][110];

void convert_map(int row,int col)
{
    int avg;
    // int a,b;
    int sum=0;
    int cnt=0;
    for(int i=0; i<h; i++){
        for(int j=0; j<l; j++){
            if(abs(i-row)+abs(j-col) <= r){
                sum+=map[i][j];
                cnt++;
            }
        }
    }
    avg = sum / cnt;
    con[row][col] = avg;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> l >> h >> r;
    for(int i=0; i<h; i++){
        for(int j=0; j<l; j++){
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < h; i++){
        for (int j = 0; j < l; j++){
            convert_map(i,j);
        }
    }

    for (int i = 0; i < h; i++){
        for (int j = 0; j < l; j++){
            cout << con[i][j] << " ";
        }
        cout << "\n";
    }
}