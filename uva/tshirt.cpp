/*
LANG: C++
TASK: uva12022_tshirts
*/

#include<iostream>
using namespace std;

main()
{
    int n;
    int t;
    long long ans[] = {1,3,13,75,541,4683,47293,545835,7087261,102247563,1622632573};
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> t;
        cout << ans[t-1] << endl;
    }
}