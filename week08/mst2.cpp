/*
LANG: C++
TASK: mst2
*/

#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

#define MAX 100010
int n, m, a, b, w;
vector<pair<int,pair<int,int> > > graph;

/*union find*/
int parent[MAX];
int height[MAX];

void init(int node)
{
    for(int i=0; i<node; i++){
        parent[i] = i;
        height[i] = 1;
    }
}

int find(int x)
{
    while(parent[x] != x){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void unionxy(int x,int y)
{
    int px = find(x);
    int py = find(y);
    if(height[px] < height[py]){
        parent[px] = py;
        height[py]+=height[px];
    }
    else{
        parent[py] = px;
        height[px]+=height[py];
    }
}

/* mst */
int mst()
{
    int cnt = 0;
    sort(graph.begin(),graph.end());
    for(int i=0; i<m; i++){
        int x = graph[i].second.first;
        int y = graph[i].second.second;
        int px = find(x);
        int py = find(y);
        if(px != py){ //check cycle
            cnt+=graph[i].first;
            unionxy(x,y);
        }
    }
    return cnt;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b >> w;
        graph.push_back(make_pair(w,make_pair(a,b)));
    }
    init(n+1);
    cout << mst() << "\n";
}