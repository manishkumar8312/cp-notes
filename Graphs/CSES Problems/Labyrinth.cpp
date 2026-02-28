Problem Statement:
You are given a map of a labyrinth, and your task is to find a path from start to end. You can walk left, right, up and down.

Input
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the labyrinth. Each character is . (floor), # (wall), A (start), or B (end). 
There is exactly one A and one B in the input.

Output
First print "YES", if there is a path, and "NO" otherwise.
If there is a path, print the length of the shortest such path and its description as a string consisting of characters 
L (left), R (right), U (up), and D (down). You can print any valid solution.

Constraints:
1 <= n,m <= 1000

Example

Input:
5 8
########
#.A#...#
#.##.#B#
#......#
########

Output:
YES
9
LDDRRRRRU

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