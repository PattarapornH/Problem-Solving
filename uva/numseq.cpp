/*
LANG: C++
TASK: uva10706_numbersequence
*/

#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
using namespace std;

int t,n;
vector<int> seq;

void buildseq(int n)
{
    int cnt= 0;
    seq.clear();
    for(int i=1; i <= n; i++){
        for (int j = 1; j <= i && cnt < n; j++)
        {
            if(j>=10){
                int x=j;
                int p = (int)log10(x);
                int d = (int)pow(10,p);
                cnt+=p+1;
                // cout << d << endl;
                while(p>=0){
                    cout << x/d << endl;
                    if(x >= 10){
                        seq.push_back(x/d);
                    }
                    else{
                        seq.push_back(x);
                    }
                    x = x%(int)pow(10,p);
                    p--;
                }
            }
            else{
                cnt++;
                seq.push_back(j);
            }
        }
    }
}

main()
{
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        buildseq(n);
        int len=0;
        // cout <<  << endl;
        vector<int>::iterator it = seq.end();
        it--;
        cout << *it << "\n";
        // for(it=seq.begin(); it!=seq.end(); it++){
            // if(*it>=10){
            //     len += (int)log10(*it) + 1;
            // }
            // cout << *it << " ";
        // }
    }
}