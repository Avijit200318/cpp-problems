// Binary Subarrays With Sum

// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

// A subarray is a contiguous part of the array.

 

// Example 1:

// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4
// Explanation: The 4 subarrays are bolded and underlined below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// Example 2:

// Input: nums = [0,0,0,0,0], goal = 0
// Output: 15

class Solution {
public:
    int helper(vector<int> &nums, int goal){
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int ans = 0;

        // for a special case when the goal became less than to 0 then just return 0
        if(goal < 0) return 0;

        for(int right = 0; right < n; right++){
            sum += nums[right];

            while(sum > goal){
                sum -= nums[left];
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // we need to find subarray whcich sum is exactly equal to goal
        return helper(nums, goal) - helper(nums, goal-1);
    }
};