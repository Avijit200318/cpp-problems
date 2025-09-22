// Range Sum Query 2D - Immutable
// Given a 2D matrix matrix, handle multiple queries of the following type:

// Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
// Implement the NumMatrix class:

// NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
// int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
// You must design an algorithm where sumRegion works on O(1) time complexity.

// Input
// ["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
// [[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
// Output
// [null, 8, 11, 12]

// class NumMatrix {
// public:
//     vector<vector<int>> res;
//     NumMatrix(vector<vector<int>>& matrix) {
//         res = matrix;
//     }
    
//     int sumRegion(int row1, int col1, int row2, int col2) {
//         int sum = 0;
//         for(int i = row1; i<= row2; i++){
//             for(int j = col1; j<= col2; j++){
//                 sum += res[i][j];
//             }
//         }
//         return sum;
//     }
// };

class NumMatrix {
public:
    vector<vector<int>> res, board;
    NumMatrix(vector<vector<int>>& matrix) {
        res = matrix;


        int row = res.size();
        int col = res[0].size();
        vector<vector<int>> newBoard(row+1, vector<int>(col+1, 0));

        for(int i = 0; i< row; i++){
            int prefixSum = 0;
            for(int j = 0; j < col; j++){
                prefixSum += res[i][j];
                // above value we will get from the newBoard
                int above = newBoard[i][j+1];

                newBoard[i+1][j+1] = prefixSum + above;
            }
        }
        board = newBoard;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // calculation. but we are going to use the newBoard which has paddding so every value of row and col will increase by 1.
        int bottomRight = board[row2+1][col2+1];
        int topRight = board[row1+1 - 1][col2 + 1];
        int bottomLeft = board[row2+1][col1+1-1];
        int topLeft = board[row1+1-1][col1+1-1];

        return bottomRight - topRight - bottomLeft + topLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */