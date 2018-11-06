/*
LANG: C++
TASK: uva12602_nicelicenseplates
*/

#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

int convert(char inp[])
{
    int p = 2;
    int sum_lett = 0;
    int sum_dig = 0;
    for(int i=0; i<3; i++){
        sum_lett = sum_lett + ((inp[i]-'A') * pow(26,p));
        p--;
    }
    p=3;
    for(int i=4; i<8; i++){
        sum_dig = sum_dig + ((inp[i]-'0') * pow(10,p));
        // cout << inp[i]-'0' << " , " << pow(10,p) << endl;
        p--;
    }
    // cout << sum_lett << " , " << sum_dig << endl;
    return abs(sum_dig - sum_lett);
}

main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        char inp[8];
        for(int i=0; i<8; i++){
            cin >> inp[i];
        }
        int res = convert(inp);
        if(res <= 100){
            cout << "nice\n";
        }
        else{
        	cout << "not nice\n";
        }
        // for(int i=0; i<4; i++){
        //     cout << inp[i];
        // }
        // cout << "\n---------\n";
        // cout << digit;
    }
}