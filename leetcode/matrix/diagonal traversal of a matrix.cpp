// Diagonal Travarsal of a matrix
// Given a square matrix mat[][], find its diagonal pattern, where the elements are arranged linearly by traversing the matrix diagonally, as illustrated in the examples below.

// Examples:
// Input: mat[][] = [[1, 2, 3],
//                  [4, 5, 6],
//                  [7, 8, 9]]
// Output: [1, 2, 4, 7, 5, 3, 6, 8, 9]
// Explanation: 
// Start from 1. 
// Then from upward to downward diagonally i.e. 2 and 4.
// Then from downward to upward diagonally i.e 7, 5, 3.
// Then from up to down diagonally i.e 6, 8.
// Then down to up i.e. end at 9.

class Solution {
  public:
    vector<int> matrixDiagonally(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> ans(n * m, 0);
        int row = 0, col = 0;
        
        for(int i = 0; i< n * m; i++){
            ans[i] = mat[row][col];
            
            // up
            if((row + col) % 2 == 0){
                // up corner
                if(col == m-1){
                    row++;
                }
                // down corner
                else if(row == 0){
                    col++;
                }
                // default condition
                else{
                    row--;
                    col++;
                }
            }
            // down
            else{
                if(row == n-1){
                    col++;
                }
                else if(col == 0){
                    row++;
                }
                else{
                    row++;
                    col--;
                }
            }
        }
        return ans;
    }
};