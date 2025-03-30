// // House Robber II
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

class Solution {
public:
    int solve(vector<int> &arr){
        int n = arr.size();
        int prev = arr[0], prev2 = 0;
        int curr;

        for(int i = 1; i< n; i++){
            int pick = arr[i];
            if(i > 1) pick += prev2;

            int notPick = 0 + prev;

            curr = max(pick, notPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        vector<int> temp1, temp2;
        int n = nums.size();

        if(n == 1) return nums[0];

        for(int i = 0; i< n; i++){
            if(i != 0){
                temp1.push_back(nums[i]);
              // store a array with out the first element
            }

            if(i != n-1){
                temp2.push_back(nums[i]);
              // store a array with out the last element
            }
        }
      // then return the maximum value of this two array solution
        return max(solve(temp1), solve(temp2));
    }
};
