Problem Statement: Given an n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance 
between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1.If the path is 
not possible between the source cell and the destination cell, then return -1.

Note: You can move into All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they 
share an edge or a corner).

Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1

#Code:

class Solution {
public:
    vector<pair<int,int>> directions{{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        grid[0][0] = 1;
        queue<pair<int,int>> q;
        q.push({0,0});

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            int r = node.first;
            int c = node.second;
            int dist = grid[r][c];
            if(r == n-1 && c == n-1) return dist;

            for(auto dir: directions){
                int nr = r + dir.first;
                int nc = c + dir.second;
                if(nr>=0 && nr<n && nc >= 0 && nc<m && grid[nr][nc]==0){
                    q.push({nr,nc});
                    grid[nr][nc] = dist + 1;
                }
            }
        }
        return -1;

    }
};