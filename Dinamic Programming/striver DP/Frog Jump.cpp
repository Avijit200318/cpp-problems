// Problem statement
// There is a frog on the '1st' step of an 'N' stairs long staircase. The frog wants to reach the 'Nth' stair. 'HEIGHT[i]' is the height of the '(i+1)th' stair.
// If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ). If the Frog is on 'ith' staircase,
// he can jump either to '(i+1)th' stair or to '(i+2)th' stair.
// Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.

// For Example
// If the given ‘HEIGHT’ array is [10,20,30,10], 
// the answer 20 as the frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost) and then a jump from 2nd stair to
// last stair (|10-20| = 10 energy lost). So, the total energy lost is 20.

#include <bits/stdc++.h> 

int solve(int idx , vector<int> &memo, vector<int> &heights){
    if(idx == 0){
        return 0;
    }
    if(memo[idx] != -1) return memo[idx];

    int left = solve(idx-1, memo, heights) + abs(heights[idx] - heights[idx-1]);
    int right = INT_MAX;
    if(idx > 1){
        right = solve(idx - 2, memo, heights) + abs(heights[idx] - heights[idx-2]);
    }
    memo[idx] = min(left, right);
    return memo[idx];
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> memo(n+1, -1);
    return solve(n-1, memo, heights);
}

// this will take an extra space complexity o(n)

// *******tabulization form**********

#include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights)
{
    if(n == 0) return 0;
    
    vector<int> memo(n+1, -1);
    memo[0] = 0;


    for(int i = 1; i< n; i++){
        int left = memo[i-1] + abs(heights[i] - heights[i-1]);
        int right = INT_MAX;

        if(i > 1){
            right = memo[i-2] + abs(heights[i] - heights[i-2]);
        }
        memo[i] = min(left, right);
    }
    return memo[n-1];
}


