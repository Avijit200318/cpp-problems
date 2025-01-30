// 51. N-Queens -> leetcode

// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// the output is vector<vector<stirng>> then the bellow process
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

class Solution{
    public:
    // bool isSafePos(int row, int col, vector<string> board, int n){
    //     int startRow = row, startCol = col;
    //     while(startRow >= 0 && startCol >=0){
    //         if(board[startRow][startCol] == 'Q'){
    //             return false;
    //         }
    //         startRow--;
    //         startCol--;
    //     }

    //     startRow = row, startCol = col;

    //     while(startCol >= 0){
    //         if(board[startRow][startCol] == 'Q'){
    //             return false;
    //         }
    //         startCol--;
    //     }

    //     startRow = row, startCol = col;

    //     while(startRow < n && startCol >= 0){
    //         if(board[startRow][startCol] == 'Q'){
    //             return false;
    //         }
    //         startRow++;
    //         startCol--;
    //     }
    //     return true;
    // }

    // void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n){
    //     if(col == n){
    //         ans.push_back(board);
    //         return;
    //     }

    //     for(int row = 0; row < n; row++){
    //         if(isSafePos(row, col, board, n)){
    //             board[row][col] = 'Q';
    //             solve(col+1, ans, board, n);
    //             board[row][col] = '.';
    //         }
    //     }
    // }

    // vector<vector<string>> Nque(int n){
    //     vector<vector<string>> ans;
    //     vector<string> board(n, string (n, '.'));

    //     solve(0, ans, board, n);
    //     return ans;
    // }


    // but this solution take o(n^2) time to solve it.

    void solve(int col, vector<int> &leftRow, vector<int> &lowerDiagonal, vector<int>  &upperDiagonal, vector<vector<string>> &ans, vector<string> &board, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++){
            if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n-1+ col - row] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n-1+col-row] = 1;
                solve(col+1, leftRow, lowerDiagonal, upperDiagonal, ans, board, n);

                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n-1+col-row] = 0;
            }
        }
    }

    vector<vector<string>> Nque(int n){
        vector<vector<string>> ans;
        vector<string> board(n, string (n, '.'));
        vector<int> leftRow(n, 0), lowerDiagonal(2*n -1, 0), upperDiagonal(2*n - 1, 0);

        solve(0, leftRow, lowerDiagonal, upperDiagonal, ans, board, n);
        return ans;
    }
};


// gfg -> N-Queen Problem

// Input: n = 4
// Output: [[2 4 1 3 ] [3 1 4 2 ]]
// Explaination: There are 2 possible solutions for n = 4.


//{ Driver Code Starts
// Initial Template for C++


class Solution {
  public:
  void solve(int col, vector<int> &leftRow, vector<int> &lowerDiagonal, vector<int> &upperDiagonal, vector<vector<string>> &ans, vector<string> &board, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++){
            if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n-1+ col - row] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n-1+col-row] = 1;
                solve(col+1, leftRow, lowerDiagonal, upperDiagonal, ans, board, n);

                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n-1+col-row] = 0;
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> res;
        vector<vector<string>> ans;
        vector<string> board(n, string (n, '.'));
        vector<int> leftRow(n, 0), lowerDiagonal(2*n -1, 0), upperDiagonal(2*n - 1, 0);

        solve(0, leftRow, lowerDiagonal, upperDiagonal, ans, board, n);
        
        for(int i = 0; i < ans.size(); i++){
            vector<int> temp;
            for(int row = 0; row < n; row++){  // Iterate over rows
                for(int col = 0; col < n; col++){  // Iterate over columns in the row
                    if(ans[i][row][col] == 'Q'){  // Check where 'Q' is placed
                        temp.push_back(col + 1);  // Store column (1-based index)
                        break;  // Stop after finding the queen in the row
                    }
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
