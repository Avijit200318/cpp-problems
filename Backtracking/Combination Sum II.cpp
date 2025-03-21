// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

class Solution {
public:
    void solve(int idx, int n, int target, vector<int> &arr, set<vector<int>> &ans, vector<int> &current){
        if(idx == n){
            if(target == 0){
                ans.insert(current);
            }
            return;
        }

        if(arr[idx] <= target){
            current.push_back(arr[idx]);
            solve(idx+1, n, target-arr[idx], arr, ans, current);
            current.pop_back();
        }

        solve(idx+1, n, target, arr, ans, current);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
     set<vector<int>> ans;
     vector<int> current;
    int n = candidates.size();
    sort(candidates.begin(), candidates.end());
     solve(0, n, target, candidates, ans, current);

     return vector<vector<int>> (ans.begin(), ans.end());
    }
};

// but it will show you timelimmit exceed because the overall time complexity for this code is o(2^n * nlogn) since we are using set so the time complexity increased o(2^n * n) to this



// optimal solution

class Solution {
public:
    void solve(int idx, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &current){
        if(target == 0){
            ans.push_back(current);
            return;
        }

        for(int i = idx; i< arr.size(); i++){
            if(i > idx && arr[i]== arr[i-1]) continue;
            if(arr[i] > target) break;

            current.push_back(arr[i]);
            solve(i+1, target-arr[i], arr, ans, current);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;

        sort(candidates.begin(), candidates.end());

        solve(0, target, candidates, ans, current);
        return ans;
    }
};

// here the time complexity become o(2^n * n)
