Problem Statement:
Byteland has n cities, and m roads between them. The goal is to construct new roads so that there is a route between any two cities.
Your task is to find out the minimum number of roads required, and also determine which roads should be built.

Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
After that, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
A road always connects two different cities, and there is at most one road between any two cities.

Output
First print an integer k: the number of required roads.
Then, print k lines that describe the new roads. You can print any valid solution.

Constraints:
1 <= n <= 10^5
1 <= m <= 2 * 10^5
1 <= a,b <= n

Example
Input:
4 2
1 2
3 4

Output:
1
2 3

// DFS Implementation
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> vis;

void dfs(int node){
    vis[node] = true;

    for(int v : adj[node]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    adj.resize(n + 1);
    vis.assign(n + 1, false);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> comp;

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            comp.push_back(i);
            dfs(i);
        }
    }

    cout << comp.size() - 1 << "\n";

    for(int i = 1; i < comp.size(); i++){
        cout << comp[0] << " " << comp[i] << "\n";
    }
}