#include<iostream>
#include<cstring>
using namespace std;

bool check_aeiou(char ch)
{
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
        return true;
    }
    else{
        return false;
    }
}

int count(string inp)
{
    int cnt = 0;
    int len = 0;
    while(len<inp.length()){
        if(check_aeiou(inp[len])){
            len++;
            while(check_aeiou(inp[len])){
                len++;
            }
            cnt++;
        }
        len++;
    }
    return cnt;
}
main()
{
    int N;
    string inp;
    cin >> N;
    int opt[N];
    for(int i=0; i<N; i++){
        cin >> inp;
        opt[i] = count(inp);
    }

    //OUTPUT
    for(int i=0; i<N; i++){
        cout << opt[i] << endl;
    }
}