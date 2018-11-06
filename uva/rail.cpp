/*
LANG: C++
TASK: uva514_rails
*/

#include<iostream>
#include<stack>
using namespace std;

int n;
int train[10000];

bool find_ans()
{
    int curr = 1;
    int index = 0;
    stack<int> sta;
    while (curr <= n){
        sta.push(curr);
        while (!sta.empty() && sta.top() == train[index]){
            // cout << t << endl;
            sta.pop();
            index++;
            if (index >= n){
                break;
            }
        }
        curr++;
    }
    return sta.empty();
}


main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    while(true){
        cin >> n;
        if(n == 0){
            break;
        }
        while(true){
            cin >> train[0];
            if(train[0] == 0){
                cout << "\n";
                break;
            }
            for(int i=1; i<n; i++){
                cin >> train[i];
            }
            
            if(find_ans()){
                cout << "Yes\n";
            }
            else{
                cout << "No\n";
            }
        }
    }

}
