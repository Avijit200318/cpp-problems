// //  Maximum Path Sum in the matrix
// You have been given an N*M matrix filled with integer numbers, find the maximum sum that can be obtained from a path starting from any cell
// in the first row to any cell in the last row.

// From a cell in a row, you can move to another cell directly below that row, or diagonally below left or right. So from a particular cell
// (row, col), we can move in three directions i.e.

// Down: (row+1,col)
// Down left diagonal: (row+1,col-1)
// Down right diagonal: (row+1, col+1)

// ****Normal solution***
#include <bits/stdc++.h> 

int solve(int i, int j,int n,int m, vector<vector<int>> &arr){
    if(j < 0 || j >= m) return -1e9;
    if(i == 0) return arr[0][j];

    int top = arr[i][j] + solve(i-1, j, n, m, arr);
    int left = arr[i][j] + solve(i-1, j-1, n, m, arr);
    int right = arr[i][j] + solve(i-1, j+1, n, m, arr);

    return max(top, max(left, right));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int maxVal = INT_MIN;
    for(int i = 0; i< m; i++){
        maxVal = max(maxVal, solve(n-1, i, n, m, matrix));
    }
    return maxVal;
}

// ****memorization*****

#include <bits/stdc++.h> 

int solve(int i, int j,int n,int m, vector<vector<int>> &arr, vector<vector<int>> &dp){
    if(j < 0 || j >= m) return -1e9;
    if(i == 0) return arr[0][j];
    if(dp[i][j] != -1) return dp[i][j];

    int top = arr[i][j] + solve(i-1, j, n, m, arr, dp);
    int left = arr[i][j] + solve(i-1, j-1, n, m, arr, dp);
    int right = arr[i][j] + solve(i-1, j+1, n, m, arr, dp);

    dp[i][j] = max(top, max(left, right));
    return dp[i][j];
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int> (m, -1));

    int maxVal = INT_MIN;
    for(int i = 0; i< m; i++){
        maxVal = max(maxVal, solve(n-1, i, n, m, matrix, dp));
    }
    return maxVal;
}

// tabulation*****
#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int j = 0; j< m; j++){
        dp[0][j] = matrix[0][j];
    }

    for(int i = 1; i< n; i++){
        for(int j = 0; j< m; j++){
            int top = matrix[i][j] + dp[i-1][j];
            int left = matrix[i][j];
            if(j-1 >= 0) left += dp[i-1][j-1];
            else left = -1e9;
            // if it did't match the condition then we will store very small number so that when we 
            // will get the max value it will ignore it.
            int right = matrix[i][j];
            if(j+1 < m) right += dp[i-1][j+1];
            else right = -1e9;
            dp[i][j] = max(top, max(left, right));
        }
    }

    int maxi = INT_MIN;
    for(int i = 0; i< m; i++){
        maxi = max(maxi, dp[n-1][i]);
    }
    return maxi;
}

// ***more optimal***
#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> prev(m, 0);

    for(int j = 0; j< m; j++){
        prev[j] = matrix[0][j];
    }

    for(int i = 1; i< n; i++){
        vector<int> temp(m, 0);
        for(int j = 0; j< m; j++){
            int top = matrix[i][j] + prev[j];
            int left = matrix[i][j];
            if(j-1 >= 0) left += prev[j-1];
            else left = -1e9;
            // if it did't match the condition then we will store very small number so that when we 
            // will get the max value it will ignore it.
            int right = matrix[i][j];
            if(j+1 < m) right += prev[j+1];
            else right = -1e9;
            temp[j] = max(top, max(left, right));
        }
        prev = temp;
    }

    int maxi = INT_MIN;
    for(int i = 0; i< m; i++){
        maxi = max(maxi, prev[i]);
    }
    return maxi;
}
