#include<iostream>
using namespace std;

main()
{
    char ch[100];
    int cnt = 0,len = 0;
    cin >> ch ;
    while(ch[cnt] != '\0'){
        len++;
        cnt++;
    }
    char upper[len];
    for(int i=0; i<len; i++){
        if(ch[i] >= 'a' && ch[i] <= 'z'){
            upper[i] = ch[i] - 'a' + 'A';
        }
        else{
            upper[i] = ch[i];
        }
    }

    for(int i=0; i<len;i++){
        cout << upper[i] ;
    }
    cout << endl;
}