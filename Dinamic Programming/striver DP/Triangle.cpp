// Triangle

// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move
// to either index i or index i + 1 on the next row.

// Example 1:

// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
// Example 2:

// Input: triangle = [[-10]]
// Output: -10

// ***normal recursion solution****
class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>> &arr){
        if(i == n-1){
            return arr[i][j];
        }

        int left = arr[i][j] + solve(i+1, j, n, arr);
        int right = arr[i][j] + solve(i+1, j+1, n, arr);

        return min(left, right);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        return solve(0, 0, n, triangle);
    }
};

// ****memo*****
class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>> &arr, vector<vector<int>> &dp){
        if(i == n-1){
            return arr[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];

        int left = arr[i][j] + solve(i+1, j, n, arr, dp);
        int right = arr[i][j] + solve(i+1, j+1, n, arr, dp);

        dp[i][j] = min(left, right);
        return min(left, right);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));

        return solve(0, 0, n, triangle, dp);
    }
};

// ****tabulation******
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int j = 0; j< n; j++){
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i = n-2; i>= 0; i--){
            for(int j = i; j>= 0; j--){
                int left = triangle[i][j] + dp[i+1][j];
                int right = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(left, right);
            }
        }
        return dp[0][0];
    }
};

// ***more optimize solution****
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> nextRow(n, 0);
        // we don't need the whole 2d matrix instead of we can use only 1d array
        // because to calculate min path we just need values from the next row

        for(int j = 0; j< n; j++){
            nextRow[j] = triangle[n-1][j];
        }

        for(int i = n-2; i>= 0; i--){
            vector<int> temp(n, 0);
            for(int j = i; j>= 0; j--){
                int left = triangle[i][j] + nextRow[j];
                int right = triangle[i][j] + nextRow[j+1];

                temp[j] = min(left, right);
            }
            nextRow = temp;
        }
        return nextRow[0];
    }
};
