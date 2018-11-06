#include<iostream>
using namespace std;

void find_max(int* max,int old)
{
    if(old > *max){
        *max = old;
    }
}

int count_cir(int x)
{
    int cnt = 1;
    while(true){
        if(x%2 == 0){
            x = x/2;
        }
        else if(x%2 == 1 && x != 1){
            x = ((3*x)+1);
        }
        else if(x == 1){
            break;
        }
        cnt++;
    }
    return cnt;
}

main()
{
    int a,b;
    int max = 0;
    while(!cin.eof()){
        cin >> a;
        if(cin.eof()) {
            break;
        }
        cin >> b;
        if(a<b){
            for(int i=a; i<=b; i++){
                find_max(&max,count_cir(i));
            }
        }
        else{
            for(int i=b; i<=a; i++){
                find_max(&max,count_cir(i));
            }
        }
        cout << a << " " << b << " "<< max << endl;
        max = 0;
    }
}