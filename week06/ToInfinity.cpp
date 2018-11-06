#include<iostream>
#include<cmath>
using namespace std;


int findMin(int ans,int inp)
{
    if(inp < ans){
        return inp;
    }
    return ans;
}
main()
{
    int N;
    int x,y,r;
    int ans = 999999;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> x >> y >> r;
        if(abs(y)-r <= 0){
            ans = -1;
            break;
        }
        else{
            ans = findMin(ans,abs(y)-r);
        }
    }
    cout << ans << endl;
}