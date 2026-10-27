// Number of Enclaves

// You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

// Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

// Example 1:


// Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
// Output: 3
// Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

class Solution {
public:
    void helper(queue<pair<int, int>>& q, vector<vector<int>>& visit, vector<vector<int>>& grid, vector<int>& delRow, vector<int>& delCol){
        
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i< 4; i++){
                int r = row + delRow[i];
                int c = col + delCol[i];

                if(r >= 0 && r < n && c >= 0 && c < m && !visit[r][c] && grid[r][c] == 1){
                    q.push({r, c});
                    visit[r][c] = 1;
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visit(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        // like dfs we don't have to call it again and again we can store all the values first in a queue then call helper function

        for(int i = 0; i< n; i++){
            if(!visit[i][0] && grid[i][0] == 1){
                q.push({i, 0});
                visit[i][0] = 1;
            }

            if(!visit[i][m-1] && grid[i][m-1] == 1){
                q.push({i, m-1});
                visit[i][m-1] = 1;
            }
        }

        for(int j = 0; j< m; j++){
            if(!visit[0][j] && grid[0][j] == 1){
                q.push({0, j});
                visit[0][j] = 1;
            }

            if(!visit[n-1][j] && grid[n-1][j] == 1){
                q.push({n-1, j});
                visit[n-1][j] = 1;
            }
        }

        helper(q, visit, grid, delRow, delCol);

        int count = 0;

        for(int i = 0; i< n; i++){
            for(int j = 0; j< m; j++){
                if(visit[i][j] == 0 && grid[i][j] == 1){
                    count++;
                }
            }
        }

        return count;
    }
};