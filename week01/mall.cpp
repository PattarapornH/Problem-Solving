#include<iostream>
using namespace std;
main()
{
    int p1,p2,p3;
    int c1=0,c2=0,c3=0;
    int n,type;
    cin >> p1;
    cin >> p2;
    cin >> p3;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> type;
        if(type == 1){
            c1++;
        }
        if(type == 2){
            c2++;
        }
        if(type == 3){
            c3++;
        }
    }
     int min = 1000000;
     if(min > (c1*p1)){
         min = (c1*p1);
     }
     if(min > (c2*p2)){
         min = (c2*p2);
     }
     if(min > (c3*p3)){
         min = (c3*p3);
     }

     cout << min << endl;
}