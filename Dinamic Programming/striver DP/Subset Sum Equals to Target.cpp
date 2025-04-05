// Subset Sum Equals to Target

// Sample Input 1:
// 2
// 4 5
// 4 3 2 1
// 5 4
// 2 5 1 6 7
// Sample Output 1:
// true
// false

// **** normal solution******
#include <bits/stdc++.h> 
bool solve(int idx, int k, vector<int> &arr){
    if(k == 0) return true;
    if(idx == 0) return (arr[0] == k);

    bool notTake = solve(idx-1, k, arr);
    bool take = false;
    if(k >= arr[idx]){
        take = solve(idx-1, k-arr[idx], arr);
    }

    return take || notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    return solve(n-1, k, arr);
}

// ***memorization******

#include <bits/stdc++.h> 
bool solve(int idx, int k, vector<int> &arr, vector<vector<int>> &dp){
    if(k == 0) return true;
    if(idx == 0) return (arr[0] == k);
    if(dp[idx][k] != -1) return dp[idx][k];

    bool notTake = solve(idx-1, k, arr, dp);
    bool take = false;
    if(k >= arr[idx]){
        take = solve(idx-1, k-arr[idx], arr, dp);
    }

    dp[idx][k] = take || notTake;
    return take || notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int> (k+1, -1));
    return solve(n-1, k, arr, dp);
}

// ****tabulation******
#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool> (k+1, false));

    for(int i = 0; i< n; i++){
        dp[i][0] = true;
    }

    dp[0][arr[0]] = true;

    for(int i = 1; i< n; i++){
         for(int target = 0; target <= k; target++){
             bool notTake = dp[i-1][target];
             bool take = false;

             if(target >= arr[i]){
                 take = dp[i-1][target-arr[i]];
             }

             dp[i][target] = take || notTake;
         }
    }
    return dp[n-1][k];
}

// *****more optimize solution*****
#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1, false), curr(k+1, false);

    prev[0] = true;
    curr[0] = true;

    prev[arr[0]] = true;

    for(int i = 1; i< n; i++){
         for(int target = 0; target <= k; target++){
             bool notTake = prev[target];
             bool take = false;

             if(target >= arr[i]){
                 take = prev[target-arr[i]];
             }

             curr[target] = take || notTake;
         }
         prev = curr;
    }
    return prev[k];
}

