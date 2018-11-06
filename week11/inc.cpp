/*
TASK: inc
*/

#include<iostream>
#include<vector>
using namespace std;

int n;
int seq[1010];
int lis[1010];
int max_seq = -1;
int index;
vector<int> long_seq[1010];

void init()
{
    for(int i=0; i<n; i++){
        lis[i] = 1;
        long_seq[i].push_back(seq[i]);
    }
}

void find_lis()
{
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(lis[j] + 1 > lis[i] && seq[j] < seq[i]){
                lis[i] = lis[j] + 1;
                long_seq[i] = long_seq[j];
                long_seq[i].push_back(seq[i]);
            }
        }
        if(lis[i] > max_seq){
            max_seq = lis[i];
            index = i;
        }
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> seq[i];
    }
    init();
    // long_seq[0].push_back(seq[0]);
    find_lis();
    // for(int i=0; i<n; i++){
    //     cout << lis[i] << " ";
    // }
    cout << max_seq << "\n";
    vector<int>::iterator it;
    for(it = long_seq[index].begin(); it != long_seq[index].end(); it++){
        cout << *it << " ";
    }
    cout << "\n";
}