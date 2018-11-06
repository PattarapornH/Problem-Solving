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
    char shift[len];
    for(int i=0; i<len; i++){
        if(ch[i] >= 'w'){
            shift[i] = 'a' + (3-('z'-ch[i]));
        }
        else{
            shift[i] = ch[i] + 4 ;
        }
    }

    for(int i=0; i<len; i++){
        cout << shift[i];
    }
    cout << endl;
}