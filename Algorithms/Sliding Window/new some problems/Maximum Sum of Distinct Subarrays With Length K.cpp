// // Maximum Sum of Distinct Subarrays With Length K
// You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

// The length of the subarray is k, and
// All the elements of the subarray are distinct.
// Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,5,4,2,9,9,9], k = 3
// Output: 15
// Explanation: The subarrays of nums with length 3 are:
// - [1,5,4] which meets the requirements and has a sum of 10.
// - [5,4,2] which meets the requirements and has a sum of 11.
// - [4,2,9] which meets the requirements and has a sum of 15.
// - [2,9,9] which does not meet the requirements because the element 9 is repeated.
// - [9,9,9] which does not meet the requirements because the element 9 is repeated.
// We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
// Example 2:

// Input: nums = [4,4,4], k = 3
// Output: 0
// Explanation: The subarrays of nums with length 3 are:
// - [4,4,4] which does not meet the requirements because the element 4 is repeated.
// We return 0 because no subarrays meet the conditions.


class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0;
        long long sum = 0;
        long long maxVal = 0;
        map<int, int> mpp;

        for(int i = 0; i< n; i++){
            // if the value is present in map then remove it until the duplicate elements remove from start.
            if(mpp.find(nums[i]) != mpp.end()){
                while(mpp.find(nums[i]) != mpp.end()){
                    sum -= nums[start];
                    mpp.erase(nums[start]);
                    start++;
                }
            }
            mpp[nums[i]]++;
            sum += nums[i];

            // window resizing
            if(i - start + 1 > k){
                sum -= nums[start];
                mpp.erase(nums[start]);
                start++;
            }

            // we will take sum if only kth size window we get. also since we did't take duplicate we can't right it 'i+1 >= k'
            if(i - start + 1 == k){
                maxVal = max(maxVal, sum);
            }
        }
        return maxVal;
    }
};