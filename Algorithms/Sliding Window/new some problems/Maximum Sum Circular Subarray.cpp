// Maximum Sum Circular Subarray

// Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

// A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

// A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

// Example 1:

// Input: nums = [1,-2,3,-2]
// Output: 3
// Explanation: Subarray [3] has maximum sum 3.
// Example 2:

// Input: nums = [5,-3,5]
// Output: 10
// Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
// Example 3:

// Input: nums = [-3,-2,-3]
// Output: -2
// Explanation: Subarray [-2] has maximum sum -2.


// cannot solved using sliding window

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN, mini = 0;
        int sum = 0, minSum = 0, normalSum = 0;

        // we will find the maximum sum, minisum sum and a normal sum. maximum sum can't be -ve in any situation, minimum sum can't be > 0 at any situation

        for(int i = 0; i< n; i++){
            sum += nums[i];
            minSum += nums[i];
            normalSum += nums[i];

            if(sum > maxi){
                maxi = sum;
            }

            if(sum < 0){
                sum = 0;
            }

            if(minSum < mini){
                mini = minSum;
            }

            if(minSum > 0){
                minSum = 0;
            }
        }
        // case when all the elemnts are -ve then the normalSum and mini will be same. next line will return 0 but the actual value is -ve
        if(normalSum == mini) return maxi;
        return max(maxi, normalSum - mini);
    }
};