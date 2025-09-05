// 1. Contains Duplicate II
// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false
// Input: nums = [1,2,3,2,2,3], k = 2
// Output: true


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int start = 0;
        map<int, int> mpp;
        int n = nums.size();
        
        for(int i = 0; i< n; i++){
            // first check if the element is present or not
            if(mpp.find(nums[i]) != mpp.end()){
                return true;
            }
            mpp[nums[i]]++;

            // remove elment from start because it greater than the window size
            if(i - start + 1 > k){
                mpp.erase(nums[start]);
                start++;
            }
        }
        return false;
    }
};