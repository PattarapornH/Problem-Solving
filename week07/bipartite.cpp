/*
LANG: C++
TASK: bipartite
*/

#include <iostream>
#include <vector>
#include<list>
using namespace std;
#define MAX_N 100010

int n, m;
vector<int> adj[MAX_N];
int deg[MAX_N];

void read_input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        deg[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        deg[u]++;
        adj[v].push_back(u);
        deg[v]++;
    }
}

bool visited[MAX_N];
int layer[MAX_N]; // use as seen flag

void init()
{
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        layer[i] = -1;
    }
}


list<int> Q;
bool bfs(int s)
{
    layer[s] = 0;
    list<int> Q;
    Q.push_back(s);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop_front();
        visited[u] = true;
        //cout << u + 1 << endl;
        for (int d = 0; d < deg[u]; d++)
        {
            int v = adj[u][d];
            if (layer[u] == layer[v]){
                return false;
            }
            if (layer[v] == -1){
                layer[v] = layer[u] + 1;
                Q.push_back(v);
            }
        }
    }
    return true;
} 

main()
{
    int k;
    cin >> k;
    for(int i=0; i<k; i++){
        read_input();
        init();
        if(bfs(0)){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }
        for(int i=0; i<n; i++){
            adj[i].clear();
        }
        Q.clear();
    }
}
