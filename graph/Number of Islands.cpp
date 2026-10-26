// Number of Islands

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3


class Solution {
public:
    // bfs traversal
    void helper(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visit){
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({row, col});
        visit[row][col] = 1;

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();


            // we will check all the 4 side
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};

            for(int i = 0; i< 4; i++){
                    int newR = r + delRow[i];
                    int newC = c + delCol[i];

                    if(newR >= 0 && newR < n && newC >= 0 && newC < m && grid[newR][newC] == '1' && visit[newR][newC] == 0){
                        q.push({newR, newC});
                        visit[newR][newC] = 1;
                    }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visit(n, vector<int>(m, 0));
        int count = 0;

        for(int row = 0; row< n; row++){
            for(int col = 0; col < m; col++){
                if(grid[row][col] == '1' && visit[row][col] == 0){
                    helper(row, col, grid, visit);
                    count++;
                }
            }
        }
        return count;
    }
};



// gfg they say 8 direction

class Solution {
  public:
  void helper(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visit){
      queue<pair<int, int>> q;
      int n = grid.size(), m = grid[0].size();
      
      q.push({row, col});
      visit[row][col] = 1;
      
      
      while(!q.empty()){
          int r = q.front().first;
          int c = q.front().second;
          q.pop();
          
          for(int i = -1; i<= 1; i++){
              for(int j = -1; j<= 1; j++){
                  int newR = r + i;
                  int newC = c + j;
                  
                  if(newR >= 0 && newR <n && newC >= 0 && newC < m && grid[newR][newC] == 'L' && visit[newR][newC] == 0){
                      q.push({newR, newC});
                      visit[newR][newC] = 1;
                  }
              }
          }
      }
      
  }
  
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visit(n, vector<int>(m, 0));
        int count = 0;
        
        for(int row = 0; row< n; row++){
            for(int col = 0; col < m; col++){
                if(visit[row][col] == 0 && grid[row][col] == 'L'){
                    helper(row, col, grid, visit);
                    count++;
                }
            }
        }
        return count;
    }
};