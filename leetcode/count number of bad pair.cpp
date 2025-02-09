
// Code
// Testcase
// Test Result
// Test Result
// 2364. Count Number of Bad Pairs
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].

// Return the total number of bad pairs in nums.

 

// Example 1:

// Input: nums = [4,1,3,3]
// Output: 5


class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int, int> mpp;
        long long n = nums.size();
        long long total = n*(n-1)/2;
        long long count = 0;
        for(int i = 0; i< n; i++){
            if(mpp.find(nums[i]-i) != mpp.end()){
                count += mpp[nums[i] - i];
            }
            mpp[nums[i] - i]++;
        }
        return total - count;
    }
};
