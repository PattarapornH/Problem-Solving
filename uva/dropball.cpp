/*
LANG: C++
TASK: uva679_droppingballs
*/

#include<iostream>
using namespace std;

main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int l;
    int d,i;
    int ans;

    while(true){
        cin >> l;
        if(l == -1){
            break;
        }
        for(int k=0; k<l; k++){
            cin >> d >> i;
            ans = 1;
            for (int j = 0; j < d-1; j++)
            {
                if (i % 2 == 0)
                { //even
                    ans = (ans * 2) + 1;
                    i = i / 2;
                }
                else
                { //odd
                    ans = ans * 2;
                    i = (i+1) / 2;
                }
            }
            cout << ans << "\n";
        }
    }
}