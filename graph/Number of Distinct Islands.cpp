// Number of Distinct Islands


// Given a grid grid[][] of size n × m, consisting of characters 'L' and 'W', where 'L' represents Land and 'W' represents Water, find the number of distinct islands in the grid. An island is a group of one or more land cells connected horizontally or vertically.

// Two islands are considered distinct if their shapes are different.
// Two islands have the same shape if one can be translated to match the other exactly. Rotation and reflection are not allowed.
// Examples :

// Input: grid[][] = [['L', 'W', 'W'], ['W', 'W', 'L'], ['L', 'W', 'W']]
// Output: 1
// Explanation: The grid contains three islands. All these islands have the same shape (a 1 × 1 block of land), so they are counted as a single distinct island.


class Solution {
  public:
    void helper(int row, int col, vector<vector<int>>& visit, vector<vector<char>>& grid, vector<pair<int, int>>& current, int row0, int col0){
        int n = grid.size();
        int m = grid[0].size();
        
        visit[row][col] = 1;
        current.push_back({row-row0, col-col0});
        
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};
        
        for(int i = 0; i< 4; i++){
            int r = row + delRow[i];
            int c = col + delCol[i];
            
            if(r >= 0 && r < n && c >= 0 && c < m && !visit[r][c] && grid[r][c] == 'L'){
                helper(r, c, visit, grid, current, row0, col0);
            }
        }
    }
  
    int countDistinctIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visit(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        
        for(int i = 0; i< n; i++){
            for(int j = 0; j< m; j++){
                if(!visit[i][j] && grid[i][j] == 'L'){
                    vector<pair<int, int>> current;
                    helper(i, j, visit, grid, current, i, j);
                    st.insert(current);
                }
            }
        }
        
        return st.size();
    }
};
