#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char dir[4] = {'D', 'U', 'R', 'L'};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    pair<int,int> start, end;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'A') start = {i, j};
            if(grid[i][j] == 'B') end = {i, j};
        }
    }

    queue<pair<int,int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<char>> parent(n, vector<char>(m));

    q.push(start);
    vis[start.first][start.second] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx >= 0 && ny >= 0 && nx < n && ny < m &&
               !vis[nx][ny] && grid[nx][ny] != '#') {

                vis[nx][ny] = true;
                parent[nx][ny] = dir[k];
                q.push({nx, ny});
            }
        }
    }

    if(!vis[end.first][end.second]) {
        cout << "NO\n";
        return 0;
    }
    string path;
    int x = end.first, y = end.second;

    while(make_pair(x, y) != start) {
        char d = parent[x][y];
        path.push_back(d);

        if(d == 'D') x--;
        else if(d == 'U') x++;
        else if(d == 'R') y--;
        else if(d == 'L') y++;
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path << "\n";

    return 0;
}