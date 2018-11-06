#include<iostream>
#include<vector>
using namespace std;

main()
{
    int num;
    char ch;
    vector<string> edit;
    vector<string>::iterator p = edit.begin();
    string str;
    cin >> num;
    int pos=0;
    for(int i=0; i<num; i++){
        cin >> ch;
        if(ch =='i'){
            cin >> str;
            edit.insert(edit.begin()+pos,str);
            pos++;
        }
        else if(ch == 'l' && pos-1 >= 0){
            pos--;
        }
        else if(ch == 'r' && pos+1 <= edit.size()){
            pos++;
        }
        else if(ch == 'b' && pos-1 >= 0){
            edit.erase(edit.begin()-1+pos);
            pos--;
        }
        else if(ch == 'd' && pos < edit.size()){
            edit.erase(edit.begin()+pos);
        }

    }
    for(p = edit.begin(); p!=edit.end(); p++){
        cout << *p << " ";
    }
    cout << endl;
}