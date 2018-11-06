/*
LANG: C++
TASK: searchsum2
*/

#include<iostream>
#include<vector>
using namespace std;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    int money;
    cin >> n >> k;
    int price[n];
    int sum_price = 0;
    int max_num;
    int sum[n];
    for(int i=0; i<n; i++){
        cin >> price[i];
        sum_price += price[i];
        sum[i] = sum_price;
    }
    // cout << "-------------------\n";
    // for(int i=0; i<n; i++){
    //     cout << sum[i] << " ";
    // }
    // cout << "\n-------------------\n";
    for(int a=0; a<k; a++){
        cin >> money;
        max_num = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(sum[j]-sum[i]+price[i] <= money && j-i+1 > max_num){
                    // cout << sum[j] - sum[i] + price[i] << " " << j-i+1 << "\n";
                    max_num = j-i+1;
                }
            }
            // cout << "-------------\n";
        }
        cout << max_num << "\n";
    }
    
}