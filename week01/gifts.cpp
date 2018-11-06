#include<iostream>
using namespace std;

main()
{
    int n,price;
    int sum = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> price;
        if(price > 0){
            sum += price;
        }
    }   
    cout << sum;
}