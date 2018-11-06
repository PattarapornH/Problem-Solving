#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
using namespace std;

main()
{
    map<int,bool> rob;
    int n,m; // n=robot m=items
    int pos;
    //auto busy = rob.begin();
    map<int,bool>::iterator busy = rob.begin();
    int item;
    int sum = 0;
    int max = -1;
    int min = 999999999;
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0; i<n; i++){
        scanf("%d",&pos);
        max = (pos>max)? pos:max;
        min = (pos<min)? pos:min;
        rob.insert(pair<int,bool>(pos,true));
    }
    for(int i=0; i<m; i++){
        scanf("%d",&item);
        // int fw=0,rev=0;
        // map<int,bool>::iterator lwf = rob.upper_bound(item);
        // map<int,bool>::iterator lwr = rob.lower_bound(item);
        map<int,bool>::iterator it = rob.begin();
        // map<int,bool>::iterator tmp_it = rob.begin();
        if(lwf == lwr){
            lwf = next(lwf);
        }
        int min_en = 99999999;
        // cout << "---UPP---> " << lwf->first << endl;
        // cout << "---PRE---> " << prev(lwf)->first << endl; 
        // cout << "---LOW---> " << lwr->first << endl;
        //map<int, bool>::iterator tmp = busy;
        int tmp=sum;
        for(it = rob.begin(); it!=rob.end(); it++){
            if(it->second){
                if(abs(it->first-item) < min_en){
                    min_en = abs(it->first-item);
                    tmp_it = it;
                }
            }
        }
        busy->second = true;
        tmp_it->second = false;
        busy = tmp_it;
        sum+=min_en;
        /*if(item>=max){
            lwr = rob.end();
            while(rev==0){
                cout << "max" << endl;
                if(lwr->second){
                    rev = abs(lwr->first-item);
                    busy->second = true;
                    lwr->second = false;
                }
                else{
                    lwr = prev(lwr);
                }
            }
            busy = lwr;
            sum+=rev;
        }
        else if(item < min){
            lwf = rob.begin();
            while(fw == 0){
                if(lwf->second){
                    fw = abs(lwf->first-item);
                    busy->second = true;
                    lwf->second = false;
                }
                else{
                    lwf = next(lwf);
                }
            }
            busy = lwf;
            sum+=fw;
        }
        else{
            while((fw == 0 || rev == 0)){
                if(fw == 0){
                    if(lwf->second){
                        fw = abs(lwf->first-item);
                        busy->second = true;
                    }
                    else{
                        lwf = next(lwf);
                    }
                }
                if(rev == 0){
                    if(lwr->second){
                        rev = abs(lwr->first-item);
                        busy->second = true;
                    }
                    else{
                        lwr = prev(lwr);
                    }
                }
            }
                if(fw<rev){
                    sum+=fw;
                    lwf->second = false;
                    busy = lwf;
                }
                else if(fw>rev){
                    sum += rev;
                    lwr->second = false;
                    busy = lwr;
                }
                else{
                    if(lwf->first<lwr->first){
                        sum += fw;
                        lwf->second = false;
                        busy = lwf;
                    }
                    else{
                        sum += rev;
                        lwr->second = false;
                        busy = lwr;
                    }
            }
        }*/
        /*cout << "---FWD---> " << fw << endl;
        cout << "---REV---> " << rev << endl;
        cout << "---ENE---> " << sum-tmp << endl;
        cout << "---SUM---> " << sum << endl;*/
    }
    //cout << "---ANS---> ";
    printf("%d\n",sum);
}
