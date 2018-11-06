/*
LANG: C++
TASK: qualitymap
*/

#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool forest = false, mineral = false;
int cnt = 0;
vector<pair<int, int> > adj[31][31];
int deg[31][31];
char field[31][31]; 
bool visited[31][31];

void read()
{
    cin >> n >> m;
    string row;
    for (int i = 0; i < n; i++){
        cin >> row;
        for(int j=0; j<m; j++){
            field[i][j] = row[j];
        }
    }
}

void init()
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            visited[i][j] = false;
            deg[i][j] = 0;
        }
    }
}

void make_adj()
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (field[i][j] == '#'){
                continue;
            }
            if (i + 1 < n){
                pair<int,int> x = make_pair(i+1,j);
                adj[i][j].push_back(x);
                deg[i][j]++;
            }
            if (i - 1 >= 0){
                pair<int, int> x = make_pair(i - 1, j);
                adj[i][j].push_back(x);
                deg[i][j]++;
            }
            if (j + 1 < m){
                pair<int, int> x = make_pair(i, j+1);
                adj[i][j].push_back(x);
                deg[i][j]++;
            }
            if (j - 1 >= 0){
                pair<int, int> x = make_pair(i, j - 1);
                adj[i][j].push_back(x);
                deg[i][j]++;
            }
        }
    }
}

void dfs(int row, int col)
{
    visited[row][col] = true;
    if (field[row][col] == '$')
    {
        mineral = true;
    }
    if (field[row][col] == '*')
    {
        forest = true;
    }
    if (field[row][col] != '#')
    {
        cnt++; // count land not water
    }
    for (int d = 0; d < deg[row][col]; d++)
    {
        pair<int, int> x = adj[row][col][d];
        if (!visited[x.first][x.second]){
            dfs(x.first, x.second);
        }
    }
}

void count_forest(int* best,int* med)
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (visited[i][j] == false)
            {
                dfs(i, j);
            }
            if (forest && mineral){
                *best += cnt;
            }
            else if (forest || mineral){
                *med += cnt;
            }
            cnt = 0;
            forest = false;
            mineral = false;
            // if (visited[i][j] == false){
            //     dfs(i, j);
            // }
        }
    }
}

main()
{
    read();
    init();
    make_adj();
    dfs(0,0);
    int best = 0, med = 0;
    count_forest(&best, &med);
    cout << best << " " << med << endl;
}
