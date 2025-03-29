// Maximum sum of non-adjacent elements

// You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two
// elements are adjacent in the given array/list.

// Sample Input 1:
// 2
// 3
// 1 2 4
// 4
// 2 1 4 9
// Sample Output 1:
// 5
// 11

// ****using memorization technique***
#include <bits/stdc++.h> 

int solve(int idx, vector<int> &nums, vector<int> &memo){
    if(idx == 0) return nums[idx];
    if(idx < 0) return 0;
    if(memo[idx] != -1) return memo[idx];

    // pick
    int pick = nums[idx] + solve(idx-2, nums, memo);
    int notPick = 0 + solve(idx - 1, nums, memo);

    memo[idx] = max(pick, notPick);
    return max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> memo(n, -1);

    return solve(n-1, nums, memo);
}

// tc = o(n) ans sc = o(n) + o(n)

// ******tabulization method *******
#include <bits/stdc++.h> 

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int idx = n;
    if(idx == 0) return nums[0];
  // means that the index is 0.
    // base case

    vector<int> memo(n, -1);
    memo[0] = nums[0];

    // the iteration will start from 1
    for(int i = 1; i< n; i++){
        int pick = nums[i];
        if(i > 1) pick += memo[i-2];
        // to avoid negative index value

        int notPick = 0 + memo[i-1];

        memo[i] = max(pick, notPick);
    }
    return memo[n-1];
}

// more optimize method********
#include <bits/stdc++.h> 

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();

    int prev = nums[0], prev2, curr;

    for(int i = 1; i< n; i++){
        int pick = nums[i];
        if(i > 1) pick += prev2;

        int notPick = 0 + prev;

        curr = max(pick, notPick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
