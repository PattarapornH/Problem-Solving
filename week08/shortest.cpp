/*
LANG: C++
TASK: shortestpath
*/

#include<iostream>
#include<vector>
#include<list>
#include <bits/stdc++.h>

using namespace std;

#define MAX 100010

int n,m;
int a,b,w;

typedef pair<int,int> exPair;

list<exPair> adj[MAX];
int mindist[MAX];

void init(int N) 
{
    for (int i = 0; i < N; i++){
        mindist[i] = 9999999;
    }
}

void read()
{
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b,w));
        adj[b].push_back(make_pair(a,w));
    }
}

void find_shortest()
{
    // 1 = source
    priority_queue<exPair,vector<exPair>,greater<exPair> > q;
    mindist[1] = 0;
    q.push(make_pair(0,1));
    while(!q.empty()){
        int x = q.top().second;
        // cout << x << "\n";
        q.pop();

        list<exPair>::iterator it;
        for(it = adj[x].begin(); it != adj[x].end(); it++){
            int y = (*it).first;
            int weight = (*it).second;
            int dist = mindist[x] + weight;
            if(mindist[y] > dist){
                mindist[y] = dist;
                q.push(make_pair(mindist[y],y));
            }
        }
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    read();
    init(n+1);
    find_shortest();
    cout << mindist[n] << "\n";
}