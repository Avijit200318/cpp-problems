// You are given a two-dimensional mat[][] of size n*m containing English alphabets and a string word. Check if the word exists on the mat. The word can be constructed by using letters from adjacent cells, either horizontally or vertically. The same cell cannot be used more than once.

// Examples :

// Input: mat[][] = [['T', 'E', 'E'], ['S', 'G', 'K'], ['T', 'E', 'L']], word = "GEEK"
// Output: true

class Solution {
  public:
    bool isSafe(int idx, int row, int col, int n, int m, vector<vector<char>>& mat, string& word, vector<vector<int>>& visit){
        if((row < n && row >= 0) && (col < m && col >=0) && mat[row][col] == word[idx] && visit[row][col] != 1) return true;
        return false;
    }
    
    bool solve(int idx, int row, int col, int n, int m, vector<vector<char>>& mat, string& word, vector<vector<int>>& visit){
        if(idx == word.size()){
            return true;
        }
        
        if(isSafe(idx, row+1, col, n, m, mat, word, visit)){
            visit[row][col] = 1;
            if(solve(idx+1, row+1, col, n, m, mat, word, visit)){
                return true;
            }
            visit[row][col] = 0;
        }
        
        if(isSafe(idx, row-1, col, n, m, mat, word, visit)){
            visit[row][col] = 1;
            if(solve(idx+1, row-1, col, n, m, mat, word, visit)){
                return true;
            }
            visit[row][col] = 0;
        }
        
        if(isSafe(idx, row, col+1, n, m, mat, word, visit)){
            visit[row][col] = 1;
            if(solve(idx+1, row, col+1, n, m, mat, word, visit)){
                return true;
            }
            visit[row][col] = 0;
        }
        
        if(isSafe(idx, row, col-1, n, m, mat, word, visit)){
            visit[row][col] = 1;
            if(solve(idx+1, row, col-1, n, m, mat, word, visit)){
                return true;
            }
            visit[row][col] = 0;
        }
        return false;
    }
    
    bool isWordExist(vector<vector<char>>& mat, string& word) {
       int n = mat.size();
       int m = mat[0].size();
       vector<vector<int>> visit(n, vector<int>(m, 0));
        
        for(int i = 0; i< n; i++){
            for(int j = 0; j< m; j++){
                if(mat[i][j] == word[0]){
                    if(solve(1, i, j, n, m, mat, word, visit)) return true;
                }
            }
        }
        return false;
        
    }
};
