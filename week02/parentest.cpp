#include<iostream>
#include<stack>
using namespace std;

bool checkType(char open,char close)
{
    bool check ;
    if((open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}')){
        check = true;
    }
    else{
        check = false;
    }
    return check;
}

bool checkParen(char ch[])
{
    stack<char> st;
    int len = 0,cnt = 0;
    while(ch[cnt] != '\0'){
        len++;
        cnt++;
    }

    for(int i=0; i<len; i++){
        if(ch[i] == '(' || ch[i] == '[' || ch[i] == '{'){
            st.push(ch[i]);
        }
        else if(ch[i] == ')' || ch[i] == ']' || ch[i] == '}'){
            if(!st.empty() && checkType(st.top(),ch[i])){
                st.pop();
            }
            else{
                return false;
            }
        }
    }

    return st.empty();
}

main()
{
    int t;
    char ch[100];
    cin >> t;
    bool res[t];
    for(int i=0; i<t; i++){
        cin >> ch ;
        res[i] = checkParen(ch);
    }

    for(int i=0; i<t; i++){
        if(res[i]){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }
    }

}