// Word Search
// Difficulty: MediumAccuracy: 32.69%Submissions: 54K+Points: 4
// You are given a two-dimensional mat[][] of size n*m containing English alphabets and a string word. Check if the word exists on the mat. The word can be constructed by using letters from adjacent cells, either horizontally or vertically. The same cell cannot be used more than once.

// Examples :

// Input: mat[][] = [['T', 'E', 'E'], ['S', 'G', 'K'], ['T', 'E', 'L']], word = "GEEK"
// Output: true

class Solution {
  public:
  bool check(int i, int j, int idx, vector<vector<char>> mat, string word, vector<vector<int>> &visited){
    if(idx == word.size()){
        return true;
    }
    if(i< 0 || j < 0 || i>= mat.size() || j >= mat[0].size() || visited[i][j] || mat[i][j] != word[idx]){
        return false;
    }
    
    visited[i][j] = 1;
    if(check(i, j+1, idx+1, mat, word, visited) || check(i, j-1, idx+1, mat, word, visited) || check(i+1, j, idx+1, mat, word, visited) || check(i-1, j, idx+1, mat, word, visited)){
        return true;
    }
    visited[i][j] = 0;
    return false;
  }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i = 0; i< n; i++){
            for(int j = 0; j< m; j++){
                if(mat[i][j] == word[0]){
                    vector<vector<int>> visited(mat.size(), vector<int>(mat[0].size(), 0));
                    if(check(i, j, 0, mat, word, visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
