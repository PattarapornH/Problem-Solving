#include <iostream>
using namespace std;


int count_char(char* st,char c)
{
    int len=0;
    for(int i=0; i<1000; i++){
        if(st[i] == '\0'){
            break;
        }
        else{
            len++;
        }
    }
    int count = 0;
    for(int i=0; i<len; i++){
        if(st[i] == c){
            count++;
        }
    }
    return count;
}


main()
{
  char st[1000];

  cin.getline(st,1000);

  cout << "space: " << count_char(st,' ') << endl;
  cout << "dot: " << count_char(st,'.') << endl;
  cout << "semi: " << count_char(st,';') << endl;
}