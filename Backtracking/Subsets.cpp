// // Subsets -> leetcode

// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]


class Solution {
public:
    void solve(int idx, int sum, int n, vector<int> &nums, vector<vector<int>> &ans, vector<int> &current){
        if(idx == n){
            ans.push_back(current);
            return;
        }

        current.push_back(nums[idx]);
        solve(idx+1, sum + nums[idx], n, nums, ans, current);

        current.pop_back();
        solve(idx+1, sum, n, nums, ans, current);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        int n = nums.size();

        solve(0, 0, n, nums, ans, current);
        return ans;
    }
};
