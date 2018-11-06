/*
LANG: C++
TASK: mid_warehouses
*/

#include <iostream>
using namespace std;

struct Subset
{
    int parent;
    int height;
} subsets[100001];

void init(int N)
{
    for (int i = 0; i < N; i++)
    {
        subsets[i].parent = i;
        subsets[i].height = 1;
    }
}

int find(int node)
{
    if (subsets[node].parent != node)
    {
        subsets[node].parent = find(subsets[node].parent);
    }
    return subsets[node].parent;
}

void do_union(int a, int b)
{
    int pa = find(a);
    int pb = find(b);

    if (subsets[pa].height > subsets[pb].height)
    {
        subsets[pb].parent = pa;
    }
    else if (subsets[pa].height < subsets[pb].height)
    {
        subsets[pa].parent = pb;
    }
    else
    {
        subsets[pb].parent = pa;
        subsets[pa].height++;
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m,k, a, b;
    
    cin >> n >> m >> k;

    init(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        do_union(a,b);
    }
    // cout << "------------------\n";
    for(int i=0; i<k; i++){
        cin >> a >> b;
        int x = find(a);
        int y = find(b);
        if(x == y){
            cout << "1\n";
        }
        else{
            cout << "0\n";
        }
    }
}