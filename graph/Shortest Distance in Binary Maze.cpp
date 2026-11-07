// Shortest Distance in Binary Maze (gfg only 4 direction)

// Given a binary matrix mat[][] containing values 0 and 1, and a source cell src[] and destination cell dest[], find the minimum number of steps required to reach the destination cell from the source cell. From any cell, you can move to its adjacent cells in the up, down, left, and right directions.

// 1 represents a traversable cell.
// 0 represents a blocked cell that cannot be visited.
// If the destination cannot be reached from the source, return -1.

// Input: mat[][] = [[1, 1, 1, 1], [1, 1, 0, 1], [1, 1, 1, 1], [1, 1, 0, 0], [1, 0, 0, 1]], src[] = [0, 1], dest[] = [2, 2]
// Output: 3
// Explanation: From (0,1), the minimum number of steps to reach (2,2) is 3.


class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
        // djiskatra's algo
        // but here we can solve it using normal queue
        queue<pair<int, pair<int, int>>> q;
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> dis(n, vector<int> (m, INT_MAX));
        
        dis[src[0]][src[1]] = 0;
        q.push({0, {src[0], src[1]}});
        
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};
        
        // if the starting point is not possible to traverse
        if(mat[src[0]][src[1]] == 0) return -1;
        // if the destination and starting point is same
        if(src == dest) return 0;
        
        while(!q.empty()){
            auto it  = q.front();
            q.pop();
            
            int d = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            
            for(int i = 0; i< 4; i++){
                int r = row + delRow[i];
                int c = col + delCol[i];
                
                if(r >= 0 && r < n && c >= 0 && c < m && mat[r][c] == 1 && d + 1 < dis[r][c]){
                    // if we find destination
                    if(r == dest[0] && c == dest[1]) return d+1;
                    
                    q.push({d+1, {r, c}});
                    dis[r][c] = d+1;
                }
            }
        }
        
        return -1;
    }
};
