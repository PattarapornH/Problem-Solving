/*
LANG: C++
TASK: jumppoint
*/

#include<iostream>
#include<stdio.h>
#include <vector>
#include<list>
#include<utility>
using namespace std;

#define MAX 1010

int n, r;
bool visited[MAX];
int deg[MAX];
int layer[MAX];
vector<int> adj[MAX];
pair<int,int> xy[MAX+2];


void read()
{
    cin >> n >> r;
    xy[0] = make_pair(0,0);
    xy[n+1] = make_pair(100,100);
    for(int i=1; i<n+1; i++){
        int x, y;
        cin >> x >> y;
        xy[i] = make_pair(x,y);
    }
}

void init()
{
    for(int i=0; i<=n+1; i++){
        visited[i] = false;
        deg[i] = 0;
        layer[i] = -1;
    }
}

void make_adj()
{
    // adj[0].push_back(0);
    // adj[n+1].push_back(100);
    for(int i=0; i<=n+1; i++){
        int x1 = xy[i].first;
        int y1 = xy[i].second;
        for(int j=i+1; j<=n+1; j++){
            int x2 = xy[j].first;
            int y2 = xy[j].second;
            int dist = ((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2));
            if(dist <= r*r){
                adj[i].push_back(j);
                adj[j].push_back(i);
                deg[i]++;
                deg[j]++;
            }
        }
    }
}

void bfs(int s)
{
    layer[s] = 0;
    list<int> Q;
    Q.push_back(s);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop_front();
        visited[u] = true;
        for (int d = 0; d < deg[u]; d++)
        {
            int v = adj[u][d];
            if (layer[v] == -1)
            {
                layer[v] = layer[u] + 1;
                Q.push_back(v);
            }
            //getchar();
        }
    }
}

main()
{
    read();
    init();
    make_adj();
    // cout << "---------------\n";
    bfs(0);
    if(visited[n+1]){
        cout << layer[n+1] << endl;
    }
    else{
        cout << -1 << endl;
    }
    // cout << "---------------\n";

}
