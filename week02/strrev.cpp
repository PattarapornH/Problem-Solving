#include<iostream>
#include<stack>
using namespace std;

main()
{
    char ch[1000];
    stack<char> st;
    cin >> ch;
    char rev[1000];
    for(int i=0; ch[i]!='\0'; i++){
        st.push(ch[i]);
    }
    for(int i=0; ch[i]!='\0'; i++){
        rev[i] = st.top();
        st.pop();
    }

    for(int i=0; ch[i]!='\0'; i++){
        cout << rev[i];
    }
    cout << endl;
}