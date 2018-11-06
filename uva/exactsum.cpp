/*
LANG: C++
TASK: uva11057_exactsum
*/

#include<iostream>
using namespace std;

int n,m;
int price[10010];
int f , b; //f = forward b = backward
int index1,index2;

void bubble_sort()
{
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (price[j] > price[j + 1]){
                int tmp = price[j];
                price[j] = price[j+1];
                price[j+1] = tmp;
            }
        }
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> n){
        for(int i=0; i<n; i++){
            cin >> price[i];
        }
        bubble_sort();
        // for(int i=0; i<n; i++){
        //     cout << price[i] << " ";
        // }
        // cout << "\n";
        f = 0;
        b = n-1;
        
        cin >> m;
        while(f < b){
            if(price[f] + price[b] < m){
                f++;
            }
            else if (price[f] + price[b] > m){
                b--;
            }
            else{
                index1 = f;
                index2 = b;
                f++;
                b--;
            }
        }
        cout << "Peter should buy books whose prices are " << price[index1] << " and " << price[index2] << ".\n\n"; 
    }
}