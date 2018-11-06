#include<iostream>
#include<stdio.h>
#include<map>
#include<stdlib.h>
using namespace std;

main()
{
    int n,q;
    int st,pr,am;
    int addr;
    map <int,int> price; 
    map <int,int> amt;
    scanf("%d",&n);
    scanf("%d", &q);
    for(int i=0;i<n;i++){
        scanf("%d", &st);
        scanf("%d", &pr);
        scanf("%d", &am);
        price.insert(pair <int,int>(st,pr));
        amt.insert(pair <int,int>(st,am));
    }
    int min = 99999999;
    auto pos = amt.begin();
    for(int i=0;i<q;i++){
        scanf("%d",&addr);
        auto lw = price.lower_bound(addr - 5);
        while(abs(addr-price.find(lw->first)->first) <= 5){
            if ( price.find(lw->first)->second < min && amt.find(lw->first)->second != 0){
                min = price.find(lw->first)->second;
                pos = lw;
            }
            lw = next(lw);
        }
        if(pos!=amt.begin()){
            (amt.find(pos->first)->second)--;
        }
        if (min == 99999999){
            min = 0;
        }
        printf("%d\n",min);
        min = 99999999;
        pos = amt.begin();
    }
}
