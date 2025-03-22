// permutation
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
  
class Solution {
public:
    void solve(vector<int> &arr, vector<vector<int>> &ans, vector<int> &current, vector<int>& freq){
        if(current.size() == arr.size()){
            ans.push_back(current);
            return;
        }

        for(int i = 0; i< arr.size(); i++){
            if(!freq[i]){
                current.push_back(arr[i]);
                freq[i] = 1;

                solve(arr, ans, current, freq);

                freq[i] = 0;
                current.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        int n = nums.size();
        vector<int> freq(n, 0);

        solve(nums, ans, current, freq);
        return ans;
    }
};

// this solution take time complexity of o(n! * n) and space complexity of o(n) + o(n)

// **using swap**
class Solution {
public:
    void solve(int idx, int n, vector<int> &arr, vector<vector<int>> &ans){
        if(idx == n){
            ans.push_back(arr);
            return;
        }

        for(int i = idx; i< n; i++){
            swap(arr[idx], arr[i]);
            solve(idx+1, n, arr, ans);
            swap(arr[idx], arr[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        solve(0 , n, nums, ans);
        return ans;
    }
};

// this solution take same time complexity as the previous but it did not take andy space complexity
