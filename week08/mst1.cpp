/*
LANG: C++
TASK: mst1
*/
#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 100010
int n, m, a, b, w;

struct Edge{
    int a;
    int b;
    int weight; 
    bool operator<(const Edge &a) const
    {
        return weight < a.weight;
    }
};

struct Edge Graph[MAX];

struct Subset
{
    int parent;
    int height;
} subsets[MAX];

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

bool compare(Edge x,Edge y)
{
    return x.weight < y.weight;
}

int mst()
{
    int cnt = 0;
    sort(Graph,Graph+MAX,compare);
    int e=0,v=0; // e=edge v=vertices
    while(v < n-1){
        struct Edge ne = Graph[e];
        e++;
        int x = find(ne.a);
        int y = find(ne.b);
        if(x != y){
            cnt+=ne.weight;
            do_union(ne.a,ne.b);
            v++;
        }
    }
    return cnt;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    init(n+1);
    for(int i=0; i<m; i++){
        cin >> a >> b >> w;
        Graph[i].a = a;
        Graph[i].b = b;
        Graph[i].weight = w;
        
    }

    cout << mst() << "\n";
    // for(int i=0; i<m; i++){
    //     if(Graph[i].weight != 0){
    //         cout << Graph[i].weight << " ";
    //     }
    // }
}