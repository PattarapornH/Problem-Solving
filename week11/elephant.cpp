/*
TASK: elephant
*/

#include<iostream>
using namespace std;

int n;
int point[100010];
int best[100010];

void init()
{
    for(int i=0; i<n; i++){
        best[i] = 0;
    }
}

void eat()
{
    for(int i=3; i<n; i++){
        if(best[i-3] + point[i] > best[i-1]){
            best[i] = best[i - 3] + point[i];
        }
        else{
            best[i] = best[i-1];
        }
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int j=0; j<n; j++){
        cin >> point[j];
    }
    init();
    best[0] = 0;
    best[1] = 0;
    best[2] = point[2];
    eat();
    cout << best[n-1] << "\n";
    for(int i=0; i<n; i++){
        cout << best[i] << " ";
    }
}