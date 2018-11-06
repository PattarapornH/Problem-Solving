#include<iostream>
using namespace std;

char* write_chars(char* dest,const char* st)
{
    for(int i=0; st[i]!='\0';i++){
        dest[i] = st[i];
    }
    return dest;
}
void escape(char* src,char* dest)
{
    for(int i=0; src[i]!='\0'; i++){
        if(src[i] == '<'){
            write_chars(dest,"&lt;");
            dest+=4;
        }
        else if(src[i] == '>'){
            write_chars(dest,"&gt;");
            dest+=4;
        }
        else if(src[i] == '\"'){
            write_chars(dest,"&quot;");
            dest+=6;
        }
        else{
            *dest = src[i];
            dest++;
        }
        
    }
    *(dest) = '\0';
}
/* LOCK */
main()
{
    char st[1000];
    char out[1000];
    int l;
    cin.getline(st,1000);
    escape(st,out);
    cout << out << endl;
}