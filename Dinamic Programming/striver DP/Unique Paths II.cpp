// Unique Paths II

//********* memorization*******

class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &dp){
        if(i >= 0 && j >= 0 && arr[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int up = solve(i-1, j, arr, dp);
        int left = solve(i, j-1, arr, dp);

        dp[i][j] = up + left;
        return up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));

     return solve(n-1, m-1, obstacleGrid, dp);
    }
};

// *********tabulization*****
class Solution {
public:
    int mod = 1e9+7;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1) return 0;
        if(n == 1 && m == 1) return 1;
        if(n == 0 || m == 0) return 0;

        vector<vector<int>> dp(n, vector<int> (m, -1));

        for(int i = 0; i< n; i++){
            for(int j = 0; j< m; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else if(i == 0 && j == 0){
                    dp[0][0] = 1;
                }
                else{
                    int up = i-1 >= 0? dp[i-1][j] : 0;
                    int left = j-1 >= 0? dp[i][j-1] : 0;

                    dp[i][j] = up + left;
                }
            }
        }
        return dp[n-1][m-1];
    }
};
