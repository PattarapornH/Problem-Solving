/*
LANG: C++
TASK: uva10050_hartals
*/

#include<iostream>
using namespace std;

int t, n, p;
int party[110];

bool check_day(int d)
{
    for (int k = 0; k < p; k++){
        if (d % party[k] == 0){
            return true;
        }
    }
        
return false;
}

main()
{
    int cnt = 0;
    cin >> t;
    for(int i=0; i<t; i++){
        // cout << "=============\n";
        cin >> n >> p;
		// init(party);
        for(int j=0; j<p; j++){
            cin >> party[j];
        }
        for(int d=1; d<=n; d++){
            if(d%7 != 6 && d%7 != 0 && check_day(d)){
                cnt++;
            }
        }
        // cout << "--------\n";
        cout << cnt << endl;
        cnt = 0;
    }
}