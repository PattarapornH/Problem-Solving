#include<iostream>
#include<map>
#include<stdio.h>
#include<iterator>
using namespace std;

main()
{
    int n;
    int like;
    map<int,int> status;
    int maxlike = -1;
    int maxst = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&like);
        if(!status.count(like)){
            status.insert(pair<int, int>(like, 1));
        }
        else{
            (status.find(like)->second)++;
        }

        if(status.find(like)->second >= maxlike){
            printf("%d\n",status.find(like)->first);
            maxst = status.find(like)->first;
            maxlike = status.find(like)->second;
        }
        else{
            printf("%d\n",maxst);
        }
    }
}
