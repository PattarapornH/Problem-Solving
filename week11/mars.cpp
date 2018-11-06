/*
LANG: C++
TASK: mars
*/

#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

int n;
string txt;

int w1='A',w2='A'; // wheel1 wheel2
int drop=0;
main()
{
    cin >> n;
    for(int i=0; i<n; i++){
        drop=0;
        cin >> txt;
        for(int j=0; j<txt.length(); j++){
            if(txt[j]-'A' <= 13){
                if(txt[j] != w1){
                    drop += abs(txt[j]-w1);
                    w1 = txt[j];
                }
            }
            else{
                if(txt[j] != w2){
                    drop += abs(txt[j]-w2);
                    w2 = txt[j];
                }
            }
        }
        cout << drop << "\n";
    }
}