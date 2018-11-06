
#include <iostream>
#include<cstdlib>
using namespace std;

int n,m;
int arr[100010];
int rate[100010];

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++){
        rate[i] = 0;
    }
    rate[0] = 1;
    for (int i = 0; i < m; i++){
        for (int j = -6; j <= -1; j++){
            if(i+j >= 0 && arr[i] == arr[i+j]){
                    rate[i] = rate[i+j]+1;
                }
        }
        if(rate[i] == 0){
            rate[i] = 1; 
        }
    }
    // cout << "--------------------\n";
    // for(int i=0; i<m; i++){
    //     cout << rate[i] << " ";
    // }
    // cout << "\n";
    int max_len = -1;
    int index;
    for(int i=0; i<m; i++){
        if(rate[i] > max_len){
            max_len = rate[i];
            index = i;
        }
        else if(rate[i] == max_len){
            if(arr[i] < arr[index]){
                max_len = rate[i];
                index = i;
            }
        }
    }
    cout << arr[index] << " " << max_len << "\n";
}   