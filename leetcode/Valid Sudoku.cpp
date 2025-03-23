class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int i = 0; i< 9; i++){

            // just a small update, avoid the element to row, col position means its actual position
            // means we are checking is this element is present in row, col and 3x3 matrix
            if(i != col && board[row][i] == c) return false;

            if(i != row && board[i][col] == c) return false;

            int x = 3 * (row / 3) + i / 3;
            int y = 3 * (col / 3) + i % 3;
            if(x != row && y != col && board[x][y] == c) return false;
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i< board.size(); i++){
            for(int j = 0; j< board[0].size(); j++){
                if(board[i][j] != '.'){
                    if(!isValid(board, i, j, board[i][j])){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
