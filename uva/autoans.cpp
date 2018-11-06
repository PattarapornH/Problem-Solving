/*
LANG: C++
TASK: uva11547_automatic
*/

#include<iostream>
using namespace std;

main()
{
    int n;
    int inp;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> inp;
        inp*=567;
        inp/=9;
        inp+=7492;
        inp*=235;
        inp/=47;
        inp-=498;
        if(inp < 0){
            inp*=-1;
        }
        cout << (inp/10)%10 << endl;
    }
}