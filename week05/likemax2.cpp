/*
LANG: C++
TASK: likemax2
*/

#include<iostream>
#include<map>
#include<stdio.h>
#include<iterator>
using namespace std;

main()
{
    int n;
    int like;
    int op;
    map<int,int> status;
    int firstlike = -1;
    int firstst = 0;
    int secondlike = -1;
    int secondst = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&op,&like);
        if(op == 1){
            if (!status.count(like)){
                status.insert(pair<int, int>(like, 1));
            }
            else{
                (status.find(like)->second)++;
            }
        }
        else if(op == 0){
            if(!status.count(like)){
                status.insert(pair<int, int>(like, 0));
            }
            else{
                (status.find(like)->second)--;
            }
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
