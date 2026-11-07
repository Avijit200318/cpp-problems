// // Shortest Distance in Binary Maze2 (Leetcode 8 directions)

// 1091. Shortest Path in Binary Matrix
// Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.

// Input: grid = [[0,1],[1,0]]
// Output: 2
// Example 2:


// Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
// Output: 4
// Example 3:

// Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
// Output: -1


class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        vector<int> des = {n-1, n-1};

        // if the first cell is not valid or if there is only one cell then return 1
        if(grid[0][0] == 1) return -1;
        if(n == 1) return 1;

        // for leetcode specifically they increased ans by 1. means distance will start from 1
        q.push({1, {0, 0}});
        dis[0][0] = 1;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int d = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            // for 8 directions
            for(int i = -1; i<= 1; i++){
                for(int j = -1; j<= 1; j++){
                    if(i == 0 && j == 0) continue;

                    int r = row + i;
                    int c = col + j;

                    if(r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 0 && d + 1 < dis[r][c]){
                        if(r == des[0] && c == des[1]) return d+1;

                        dis[r][c] = d + 1;
                        q.push({d+1, {r, c}});
                    }
                }
            }
        }

        return -1;
    }
};