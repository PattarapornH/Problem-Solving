/*
LANG: C++
TASK: uva151_powercrisis
*/

#include<iostream>
#include<vector>
using namespace std;

int n;
int cnt = 0;
vector<int> num;

void init()
{
    num.clear();
    for (int i = 1; i <= n; i++)
    {
        num.push_back(i);
    }
}

bool check_last(int m)
{
    init();
    while (num[cnt] != 13)
    {
        num.erase(num.begin() + cnt);
        cnt += m - 1;
        if (cnt >= num.size()){
            cnt = cnt % num.size();
        }
        // cout << cnt << endl;
    }

    return num.size() == 1;
}

main()
{
    while(true){
        cin >> n;
        if (n == 0){
            break;
        }
        int m = 1;
        // cnt = 0;
        while (!check_last(m))
        {
            // cout << "P\n";
            m++;
            cnt = 0;
            // cout << m << " " ;
        }
        cout << m << endl;
    }
}