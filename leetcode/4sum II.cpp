// 454. 4Sum II
// Solved
// Medium
// Topics
// Companies
// Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

// 0 <= i, j, k, l < n
// nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 

// Example 1:

// Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
// Output: 2

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        map<int, int> mpp;

        for(int i = 0; i< n; i++){
            for(int j = 0; j< n; j++){
                mpp[nums1[i] + nums2[j]]++;
            }
        }
        
        int count = 0;
        for(int i = 0; i< n; i++){
            for(int j = 0; j< n; j++){
                if(mpp.find(0 - nums3[i] - nums4[j]) != mpp.end()){
                    count += mpp[0 - nums3[i] - nums4[j]];
                }
            }
        }
        return count;
    }
};
