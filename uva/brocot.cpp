/*
LANG: C++
TASK: uva10077_sternbrocot
*/

#include<iostream>
using namespace std;

int n,m;
int check_n;
int check_m;

main()
{
    while(true){
        cin >> m >> n; //fraction m/n
        if(n == 1 && m == 1){
            break;
        }
        int pre_n = 1, pre_m = 0;
        int post_n = 0, post_m = 1;
        while (true){
            check_n = pre_n + post_n;
            check_m = pre_m + post_m;
            if (check_n == n && check_m == m){
                break;
            }
            if(check_m * n > check_n * m){
                post_n = check_n;
                post_m = check_m;
                cout << "L";
            }
            else{
                pre_n = check_n;
                pre_m = check_m;
                cout << "R";
            }
        }
        cout << "\n";
    }
}