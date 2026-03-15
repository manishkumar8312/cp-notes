Problem Statement:
You are given a map of a building, and your task is to count the number of its rooms. The size of the 
map is n x m squares, and each square is either floor or wall. You can walk left, right, up, and 
down through the floor squares.

Input
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the map. Each character is either . (floor) or # (wall).

Output
Print one integer: the number of rooms. 

Input
5 8
########
#..#...#
####.#.#
#..#...#
########

Output
3

Constraints
1 <= n,m <= 1000

// DFS Implementation
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<bool>> vis;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    vis[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (!vis[nx][ny] && grid[nx][ny] == '.') {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    grid.resize(n);
    vis.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int rooms = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                rooms++;
                dfs(i, j);
            }
        }
    }

    cout << rooms << "\n";
    return 0;
}



// BFS Implementation

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<string> grid;
vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

void bfs(int r, int c){
    queue<pair<int,int>> q;
    q.push({r,c});
    grid[r][c] = '#';  // mark visited

    while(!q.empty()){
        auto node = q.front();
        q.pop();

        int x = node.first;
        int y = node.second;

        for(auto d : dir){
            int nx = x + d.first;
            int ny = y + d.second;

            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]=='.'){
                grid[nx][ny] = '#';   // mark visited
                q.push({nx,ny});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    grid.resize(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];   // string input
    }

    int rooms = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.'){
                bfs(i, j);
                rooms++;
            }
        }
    }

    cout << rooms << "\n";
}








