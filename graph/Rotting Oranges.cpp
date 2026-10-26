// Rotting Oranges

// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

class Solution {
public:
    void helper(int n, int m, int& minTime, queue<pair<pair<int, int>, int>>& q, vector<vector<int>>& grid, vector<vector<int>>& ans, vector<int>& delRow, vector<int>& delCol){
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();

            minTime = max(minTime, time);

            for(int i = 0; i< 4; i++){
                int r = row + delRow[i];
                int c = col + delCol[i];

                if(r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && ans[r][c] != 2){
                    q.push({{r, c}, time+1});
                    ans[r][c] = 2;
                }
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        int minTime = 0;

        for(int i = 0; i< n ;i++){
            for(int j = 0; j< m; j++){
                if(grid[i][j] == 2){
                    ans[i][j] = 2;
                    q.push({{i, j}, 0});
                }
            }
        }

        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        helper(n, m, minTime, q, grid, ans, delRow, delCol);

        for(int i = 0; i< n; i++){
            for(int j = 0; j< m; j++){
                if(grid[i][j] == 1 && ans[i][j] != 2){
                    return -1;
                }
            }
        }

        return minTime;
    }
};