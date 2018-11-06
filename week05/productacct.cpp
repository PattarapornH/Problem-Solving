#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;

main()
{
    int M;
    int num;
    map<int,int> store;
    int type,amt;
    scanf("%d",&M);
    int res[M];
    for(int i=0; i<M; i++){
        scanf("%d",&num);
        if(num == 1){
            scanf("%d", &type);
            scanf("%d", &amt);
            if (!store.count(type)){
                store.insert(pair<int,int>(type,amt));
            }
            else{
                store.find(type)->second += amt;
            }
        }
        else if(num == 2){
            scanf("%d", &type);
            if (!store.count(type)){
                printf("0\n");
            }
            else{
                printf("%d\n", store.find(type)->second);
            }
        }
        else if(num == 3){
            scanf("%d", &type);
            scanf("%d", &amt);
            if(amt < store.find(type)->second){
                printf("%d\n",amt);
                store.find(type)->second -= amt;
            }
            else{
                printf("%d\n", store.find(type)->second);
                store.find(type)->second = 0;
            }
        }
    }
}