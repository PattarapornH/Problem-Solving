/*
LANG: C++
TASK: milk
*/

#include<iostream>
using namespace std;
#define MAX 100010

struct Subset {
    int parent;
    int height;
} subsets[MAX];

void init(int N) {
    for (int i = 0; i < N; i++) {
        subsets[i].parent = i;
        subsets[i].height = 1;
    }
}

int find(int node) {
    if (subsets[node].parent != node) {
        subsets[node].parent = find(subsets[node].parent);
    } 
    return subsets[node].parent;
}

void do_union(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (subsets[pa].height > subsets[pb].height) {
        subsets[pb].parent = pa;
    } else if (subsets[pa].height < subsets[pb].height) {
        subsets[pa].parent = pb;
    } else {
        subsets[pb].parent = pa;
        subsets[pa].height++;
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k,a,b;
    cin >> n >> k;
    char ch;

    init(n + 1);
    for(int i=0; i<k; i++){
        cin >> ch >> a >> b;
        if(ch == 'q'){
            int x = find(a);
            int y = find(b);
            if(x == y){
                cout << "yes\n";
            }
            else{
                cout << "no\n";
            }

        }
        else if(ch == 'c'){
            do_union(a,b);
        }
    }
}