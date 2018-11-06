#include<iostream>
#include<stack>
using namespace std;

main()
{
    char ch[1000];
    stack<char> st;
    cin >> ch;
    int len = 0,cnt = 0;
    while(ch[cnt] != '\0'){
        len++;
        cnt++;
    }
    char rev[len];
    cnt = 0;
    for(int i=0; i<len; i++){
        if(ch[i] == '_'){
            while(!st.empty()){
                rev[cnt] = st.top();
                st.pop();
                cnt++;
            }
            rev[cnt++] = ch[i];
        }
        else{
            st.push(ch[i]);
        }

        if(i == len - 1){
            while(!st.empty()){
                rev[cnt] = st.top();
                st.pop();
                cnt++;
            }
        }
    }

    for(int i=0; i<len; i++){
        cout << rev[i];
    }
    cout << endl;
}