// Distance of Nearest 1 in Grid

// Given a binary grid[][], where each cell contains either 0 or 1, find the distance of the nearest 1 for every cell in the grid.
// The distance between two cells (i1, j1)  and (i2, j2) is calculated as |i1 - i2| + |j1 - j2|. 
// You need to return a matrix of the same size, where each cell (i, j) contains the minimum distance from grid[i][j] to the nearest cell having value 1.

// Note: It is guaranteed that there is at least one cell with value 1 in the grid.

// Examples

// Input: grid[][] = [[0, 1, 1, 0], [1, 1, 0, 0], [0, 0, 1, 1]]
// Output: [[1, 0, 0, 1], [0, 0, 1, 1], [1, 1, 0, 0]]

class Solution {
  public:
    void helper(queue<pair<pair<int, int>, int>>& q, vector<vector<int>>& visit, vector<vector<int>>& grid, vector<vector<int>>& ans, vector<int>& delRow, vector<int>& delCol){
        int n = grid.size();
        int m = grid[0].size();
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int val = q.front().second;
            q.pop();
            
            ans[r][c] = val;
            
            for(int i = 0; i < 4; i++){
                int newR = r + delRow[i];
                int newC = c + delCol[i];
                
                if(newR >= 0 && newR < n && newC >= 0 && newC < m && !visit[newR][newC]){
                    q.push({{newR, newC}, val+1});
                    visit[newR][newC] = 1;
                }
            }
        }
    }
    
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visit(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        
        
        for(int i = 0; i< n; i++){
            for(int j = 0; j< m; j++){
                if(grid[i][j] == 1){
                    visit[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }
        
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};
        
        helper(q, visit, grid, ans, delRow, delCol);
        
        return ans;
    }
};



// Leetcode
// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two cells sharing a common edge is 1.

class Solution {
public:
    void helper(queue<pair<pair<int, int>, int>>& q, vector<vector<int>>& visit, vector<vector<int>>& mat, vector<vector<int>>& ans, vector<int>& delRow, vector<int>& delCol){
        int n = mat.size();
        int m = mat[0].size();

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int val = q.front().second;
            q.pop();

            ans[r][c] = val;

            for(int i = 0; i< 4; i++){
                int newR = r + delRow[i];
                int newC = c + delCol[i];

                if(newR >= 0 && newR < n && newC >= 0 && newC < m && !visit[newR][newC]){
                    q.push({{newR, newC}, val+1});
                    visit[newR][newC] = 1;
                }
            }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // we have to find nearest 0 distance
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> visit(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i< n; i++){
            for(int j = 0; j< m; j++){
                if(mat[i][j] == 0){
                    visit[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        helper(q, visit, mat, ans, delRow, delCol);

        return ans;
    }
};