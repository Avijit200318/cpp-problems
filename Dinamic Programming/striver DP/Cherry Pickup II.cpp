//Cherry Pickup II

// You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can
// collect from the (i, j) cell.

// You have two robots that can collect cherries for you:

// Robot #1 is located at the top-left corner (0, 0), and
// Robot #2 is located at the top-right corner (0, cols - 1).
// Return the maximum number of cherries collection using both robots by following the rules below:

// From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
// When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
// When both robots stay in the same cell, only one takes the cherries.
// Both robots cannot move outside of the grid at any moment.
// Both robots should reach the bottom row in grid.

// Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
// Output: 24
// Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
// Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
// Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
// Total of cherries: 12 + 12 = 24.

// ****normal solution*****

class Solution {
public:
    int solve(int i, int j1, int j2, int n, int m, vector<vector<int>> &arr){
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m){
            return -1e8;
        }
        if(i == n-1){
            if(j1 == j2){
                return arr[i][j1];
            }
            return arr[i][j1] + arr[i][j2];
        }

        int maxi = -1e9;
        for(int dj1 = -1; dj1 <= 1; dj1++){
            for(int dj2 = -1; dj2 <= 1; dj2++){
                int value = 0;
                if(j1 == j2){
                    value += arr[i][j1];
                }
                else{
                    value += arr[i][j1] + arr[i][j2];
                }
                value += solve(i+1, j1+dj1, j2+dj2, n, m, arr);
                maxi = max(maxi, value);
            }
        }
        return maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        return solve(0, 0, m-1, n,  m, grid);
    }
};

// ****memorization****
class Solution {
public:
    int solve(int i, int j1, int j2, int n, int m, vector<vector<int>> &arr, vector<vector<vector<int>>> &dp){
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m){
            return -1e8;
        }
        if(i == n-1){
            if(j1 == j2){
                return arr[i][j1];
            }
            return arr[i][j1] + arr[i][j2];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = -1e9;
        for(int dj1 = -1; dj1 <= 1; dj1++){
            for(int dj2 = -1; dj2 <= 1; dj2++){
                int value = 0;
                if(j1 == j2){
                    value += arr[i][j1];
                }
                else{
                    value += arr[i][j1] + arr[i][j2];
                }
                value += solve(i+1, j1+dj1, j2+dj2, n, m, arr, dp);
                maxi = max(maxi, value);
            }
        }
        dp[i][j1][j2] = maxi;
        return maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return solve(0, 0, m-1, n,  m, grid, dp);
    }
};

// ****tabulation******
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

        // basecase
        for(int j1 = 0; j1< m; j1++){
            for(int j2 = 0; j2 < m; j2++){
                if(j1 == j2){
                dp[n-1][j1][j2] = grid[n-1][j1];
                }
                else{
                dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
                }
            }
        }
        
        for(int i = n-2; i>= 0; i--){
            for(int j1 = 0; j1< m; j1++){
                for(int j2 = 0; j2< m; j2++){
                    int maxi = -1e8;
                    for(int dj1 = -1; dj1 <= 1; dj1++){
                        for(int dj2 = -1; dj2 <= 1; dj2++){
                            int value = 0;
                            if(j1 == j2){
                                value += grid[i][j1];
                            }
                            else{
                                value += grid[i][j1] + grid[i][j2];
                            }
                            if(j1+dj1 < m && j1+dj1 >= 0 && j2+dj2 < m && j2+dj2 >= 0){
                            value += dp[i+1][j1+dj1][j2+dj2];
                            }
                            else value += -1e8;
                            maxi = max(maxi, value);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][m-1];
    }
};

// ****more optimize solution******
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> front(m, vector<int>(m, 0));
        vector<vector<int>> curr(m, vector<int>(m, 0));

        // basecase
        for(int j1 = 0; j1< m; j1++){
            for(int j2 = 0; j2 < m; j2++){
                if(j1 == j2){
                front[j1][j2] = grid[n-1][j1];
                }
                else{
                front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
                }
            }
        }
        
        for(int i = n-2; i>= 0; i--){
            for(int j1 = 0; j1< m; j1++){
                for(int j2 = 0; j2< m; j2++){
                    int maxi = -1e8;
                    for(int dj1 = -1; dj1 <= 1; dj1++){
                        for(int dj2 = -1; dj2 <= 1; dj2++){
                            int value = 0;
                            if(j1 == j2){
                                value += grid[i][j1];
                            }
                            else{
                                value += grid[i][j1] + grid[i][j2];
                            }
                            if(j1+dj1 < m && j1+dj1 >= 0 && j2+dj2 < m && j2+dj2 >= 0){
                            value += front[j1+dj1][j2+dj2];
                            }
                            else value += -1e8;
                            maxi = max(maxi, value);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            front = curr;
        }

        return front[0][m-1];
    }
};
