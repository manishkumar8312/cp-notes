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

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // directions: up, down, left, right
    vector<vector<int>> directions{
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    int rooms = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (grid[i][j] == '.' && !visited[i][j]) {
                rooms++;

                queue<pair<int,int>> q;
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty()) {
                    auto front = q.front();
                    q.pop();
                    int r = front.first;
                    int c = front.second;
                    for (auto &d : directions) {
                        int nr = r + d[0];
                        int nc = c + d[1];

                        if (nr >= 0 && nr < n &&
                            nc >= 0 && nc < m &&
                            grid[nr][nc] == '.' &&
                            !visited[nr][nc]) {

                            visited[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }
    }

    cout << rooms << endl;
    return 0;
}








