
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

main()
{
    int N,K; // number of input
    int money; // our money
    int p; // input price
    int sum = 0; // sum price
    cin >> N >> K;
    int num[K];
    vector<int> price; //store sum
    for(int i=0; i<N; i++){
        cin >> p;
        sum+=p;
        price.push_back(sum);
    } 
    for(int i=0; i<K; i++){
        cin >> money;
        num[i] = upper_bound(price.begin(),price.end(),money) - price.begin();
    }
    for(int i=0; i<K; i++){
        cout << num[i] << endl;
    }
}