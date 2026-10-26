// Flood Fill

// You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

// To perform a flood fill:

// Begin with the starting pixel and change its color to color.
// Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
// Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
// The process stops when there are no more adjacent pixels of the original color to update.
// Return the modified image after performing the flood fill.

 

// Example 1:

// Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

// Output: [[2,2,2],[2,2,0],[2,0,1]]


// ***method 1 DFS traversal***

class Solution {
public:
    void helper(int row, int col, int initialColor, int color, vector<vector<int>>& image, vector<vector<int>>& ans, vector<int>& delRow, vector<int>delCol){
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();

        for(int i = 0; i< 4; i++){
            int r = row + delRow[i];
            int c = col + delCol[i];

            if(r >= 0 && r < n && c >= 0 && c < m && image[r][c] == initialColor && ans[r][c] != color){
                helper(r, c, initialColor, color, image, ans, delRow, delCol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans(image.begin(), image.end());
        int initialColor = image[sr][sc];

        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        helper(sr, sc, initialColor, color, image, ans, delRow, delCol);
        return ans;
    }
};




// ****2. BFS *****

class Solution {
  public:
    void helper(int row, int col, int initialColor, int color, vector<vector<int>>& image, vector<vector<int>>& ans, vector<int>& delRow, vector<int>& delCol){
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        
        queue<pair<int, int>> q;
        q.push({row, col});
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i = 0; i< 4; i++){
                int newR = r + delRow[i];
                int newC = c + delCol[i];
                
                if(newR >= 0 && newR < n && newC >= 0 && newC < m && image[newR][newC] == initialColor && ans[newR][newC] != color){
                    q.push({newR, newC});
                    ans[newR][newC] = color;
                }
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        vector<vector<int>> ans(image.begin(), image.end());
        int initialColor = image[sr][sc];
        
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};
        
        helper(sr, sc, initialColor, newColor, image, ans, delRow, delCol);
        
        return ans;
    }
};