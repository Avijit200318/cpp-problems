// Find Pivot Index
// Given an array of integers nums, calculate the pivot index of this array.

// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

// If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

// Return the leftmost pivot index. If no such index exists, return -1.

 

// Example 1:

// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum, postfixSum(n, 0);
        int idx = -1;
        int sum = 0, rSum = 0;

        for(int i = 0; i< n; i++){
            sum += nums[i];
            prefixSum.push_back(sum);

            rSum += nums[n-1-i];
            postfixSum[n-1-i] = rSum;
        }

        for(int i = 0; i< n; i++){
            if(prefixSum[i] == postfixSum[i]) return i;
        }
        return idx;
    }
};

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<int> prefixSum;

        for(int i = 0; i< n; i++){
            sum += nums[i];
            prefixSum.push_back(sum);
        }

        for(int i = 0; i< n; i++){
            // this is the edge case when i == 0 means the first element
            if(i == 0 && prefixSum[n-1] - prefixSum[i] == 0) return 0;
            // this is all the other case
            if(i > 0 && prefixSum[n-1] - prefixSum[i] == prefixSum[i-1]) return i;
        }

        return -1;
    }
};