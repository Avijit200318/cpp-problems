// subset II
// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

// in the bruteforce technique we can use pick or not pick techinique which will take time complexiy of o(2^n * n)


class Solution {
public:
    void solve(int idx, int n, vector<int> &arr, vector<vector<int>> &ans, vector<int> &current){
        ans.push_back(current);
        if(idx == n) return;

        for(int i = idx; i< arr.size(); i++){
            if(i > idx && arr[i] == arr[i-1]) continue;

            current.push_back(arr[i]);
            solve(i+1, n, arr, ans, current);
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> current;

        sort(nums.begin(), nums.end());

        solve(0, n, nums, ans, current);
        return ans;
    }
};
