// Minimum Path Sum

// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

//   Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
// Example 2:

// Input: grid = [[1,2,3],[4,5,6]]
// Output: 12

// ******Normal recursion code *********
class Solution {
public:
    long long solve(int i, int j, vector<vector<int>> &arr){
        if(i == 0 && j == 0) return arr[i][j];
        if(i < 0 || j < 0) return INT_MAX;

        long long up = arr[i][j] + solve(i-1, j, arr);
        long long left = arr[i][j] + solve(i, j-1, arr);

        return min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        return solve(n-1, m-1, grid);
    }
};

// memorization code *********
class Solution {
public:
    long long solve(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return arr[i][j];
        if(i < 0 || j < 0) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];

        long long up = arr[i][j] + solve(i-1, j, arr, dp);
        long long left = arr[i][j] + solve(i, j-1, arr, dp);

        dp[i][j] = min(up, left);
        return min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(n-1, m-1, grid, dp);
    }
};

// tabulation*****

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int> (m, 0));

        for(int i = 0; i< n; i++){
            for(int j = 0; j< m; j++){
                if(i == 0 && j== 0){
                    dp[i][j] = grid[0][0];
                }
                else{
                    int up = i-1 >= 0? grid[i][j] + dp[i-1][j] : (INT_MAX)/2;
                    int left = j-1 >= 0? grid[i][j] + dp[i][j-1] : (INT_MAX)/2;

                    dp[i][j] = min(up, left);
                }
            }
        }

        return dp[n-1][m-1];
    }
};

// *****more optimize******
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> prev(m, 0);

        for(int i = 0; i< n; i++){
            vector<int> temp(m, 0);
            for(int j = 0; j< m; j++){
                if(i == 0 && j== 0){
                    temp[j] = grid[0][0];
                }
                else{
                    int up = i-1 >= 0? grid[i][j] + prev[j] : (INT_MAX)/2;
                    int left = j-1 >= 0? grid[i][j] + temp[j-1] : (INT_MAX)/2;

                    temp[j] = min(up, left);
                }
            }
            prev = temp;
        }

        return prev[m-1];
    }
};
