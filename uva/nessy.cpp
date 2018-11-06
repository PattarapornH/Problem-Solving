/*
LANG: C++
TASK: uva11044_nessy
*/

#include<iostream>
using namespace std;

main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int r,c;
        cin >> r >> c;
        // cout << r/3 << " , " << c/3 << endl;
        cout << (r/3)*(c/3) << endl;
    }
}