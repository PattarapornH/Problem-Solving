/*
TASK: inc2
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> seq;
int n,num;

int find_index(vector<int> &vec,int len,int r,int key){
    while(r-len > 1){
        int m = len + (r-len)/2;
        if(vec[m] >= key){
            r = m;
        }
        else{
            len = m;
        }
    }
    return r;
}


int lis()
{
    vector<int> tail;
    /* init */
    for(int i=0; i<n; i++){
        tail.push_back(0);
    }
    int len = 1;
    tail[0] = seq[0];
    for(size_t i=1; i<seq.size(); i++){
        // cout << "pass";
        if(seq[i] < tail[0]){
            tail[0] = seq[i];
        }
        else if(seq[i] > tail[len-1]){
            tail[len++] = seq[i];
        }
        else{
            tail[find_index(tail,-1,len-1,seq[i])] = seq[i];
        }
    }
    return len;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num;
        seq.push_back(num);
    }
    if(seq.size() == 0){
        cout << "0\n"; 
    }
    else{
        cout << lis() << "\n";
    }
}