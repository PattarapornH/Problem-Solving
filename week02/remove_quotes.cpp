#include<iostream>
using namespace std;

void remove_quote(char* src,char* dest){
    int cnt = 0;
    for(int i=0; i<1000; i++){
        if(src[i] != '\'' && src[i] != '\"'){
            dest[cnt] = src[i];
            cnt++;        
        }
    }
}

main()
{
  char st[1000];
  char out[1000];
  int l;

  cin.getline(st,1000);
  remove_quote(st,out);

  cout << out << endl;
}