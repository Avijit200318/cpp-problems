// Surrounded Regions

// You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

// Connect: A cell is connected to adjacent cells horizontally or vertically.
// Region: To form a region connect every 'O' cell.
// Surround: A region is surrounded if none of the 'O' cells in that region are on the edge of the board. Such regions are completely enclosed by 'X' cells.
// To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

 

// Example 1:

// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]


class Solution {
public:
    void helper(int row, int col, vector<vector<int>>& visit,vector<vector<char>>& board, vector<int>& delRow, vector<int>& delCol){
        visit[row][col] = 1;
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i< 4; i++){
            int r = row + delRow[i];
            int c = col + delCol[i];

            if(r >= 0 && r < n && c >= 0 && c < m && !visit[r][c] && board[r][c] == 'O'){
                helper(r, c, visit, board, delRow, delCol);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visit(n, vector<int>(m, 0));

        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        for(int i = 0; i< n; i++){
            // first column
            if(!visit[i][0] && board[i][0] == 'O'){
                helper(i, 0, visit, board, delRow, delCol);
            }

            // last column
            if(!visit[i][m-1] && board[i][m-1] == 'O'){
                helper(i, m-1, visit, board, delRow, delCol);
            }
        }

        for(int j = 0; j< m; j++){
            // first row
            if(!visit[0][j] && board[0][j] == 'O'){
                helper(0, j, visit, board, delRow, delCol);
            }

            // last row
            if(!visit[n-1][j] && board[n-1][j] == 'O'){
                helper(n-1, j, visit, board, delRow, delCol);
            }
        }


        for(int i = 0; i< n; i++){
            for(int j = 0; j< m; j++){
                if(!visit[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};