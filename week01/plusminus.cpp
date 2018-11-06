#include<iostream>
using namespace std;

main()
{
    int n ;
    char op1;
    int op2 ;
    int res = 0 ;
    int operand;
    cin >> n;
    cin >> op2 ; // input first operand
    res = op2 ;
    for(int i = 1 ; i < n; i++){
        cin >> op1 >> op2;
        if(op1 == '+'){
            res += op2;
        }
        else if(op1 == '-'){
            res -= op2;
        }
    }
    cout << res << endl;
}