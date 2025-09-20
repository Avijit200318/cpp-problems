// 80. Remove Duplicates from Sorted Array II
// Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

// Input: nums = [1,1,1,2,2,3]
// Output: 5, nums = [1,1,2,2,3,_]
// Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        int left = 0;
        for(int right = 0; right < n; right++){
            ans.push_back(nums[right]);
            if(nums[right] == nums[left]){
                if(right - left + 1 > 2){
                    // if the element occure more than 2 times then remove last element
                    ans.pop_back();
                }
            }
            else{
                // when left and right not same set left = right
                left = right;
            }
        }
        
        for(int i = 0; i< ans.size(); i++){
            nums[i] = ans[i];
        }

        return ans.size();
    }
};