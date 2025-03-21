// Combination Sum III

// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

// Example 1:

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.
// Example 2:

// Input: k = 3, n = 9
// Output: [[1,2,6],[1,3,5],[2,3,4]]
// Explanation:
// 1 + 2 + 6 = 9
// 1 + 3 + 5 = 9
// 2 + 3 + 4 = 9
// There are no other valid combinations.
// Example 3:

// Input: k = 4, n = 1
// Output: []
// Explanation: There are no valid combinations.
// Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.



// **********we just need to check pick elemnet or not since there is not use of set and all elements are unique*********
class Solution {
public:
    void solve(int idx, int n, int target, int needSize, vector<int> &arr, vector<vector<int>> &ans, vector<int> &current){
        if(idx == n){
            if(target == 0 && needSize == current.size()){
              // just update this line 
                ans.push_back(current);
            }
            return;
        }

        if(arr[idx] <= target){
            current.push_back(arr[idx]);
            solve(idx+1, n, target-arr[idx], needSize, arr, ans, current);
            current.pop_back();
        }

        solve(idx+1, n, target, needSize, arr, ans, current);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> ans;
        vector<int> current;

        solve(0, 9, n, k, arr, ans, current);
        return ans;
    }
};
