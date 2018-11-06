/*
LANG: C++
TASK: uva299_trainswapping
*/

#include<iostream>
using namespace std;

int n,l;
int train[100];

int bubble_sort()
{
    int swap = 0;
    for(int i=0; i<l-1; i++){
        for(int j=i+1; j<l; j++){
            if(train[i] > train[j]){
                swap++;
            }
        }
    }
    return swap;
}

main()
{
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> l;
        for(int j=0; j<l; j++){
            cin >> train[j];
        }
        cout << "Optimal train swapping takes " << bubble_sort() << " swaps." << endl;
    }
}