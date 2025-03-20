#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void solve(int idx, int n, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &current){
        if(idx == n){
            // if the target also become 0 then push all the elements
            if(target == 0){
                ans.push_back(current);
            }
            return;
        }

        if(arr[idx] <= target){
            current.push_back(arr[idx]);
            // since we can use each element multiple times because of it we did't change the idx value
            solve(idx, n, target-arr[idx], arr, ans, current);
            current.pop_back();
        }

        // if we can't take the first value or the first element is greate than the target
        solve(idx+1, n, target, arr, ans, current);
    }

    vector<vector<int>> combinationSum(vector<int> arr, int target){
        vector<vector<int>> ans;
        vector<int> current;
        int n = arr.size();

        solve(0, n, target, arr, ans, current);
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> arr = {2, 3, 6, 7};
    vector<vector<int>> a = s.combinationSum(arr, 7);
    for(int i = 0; i< a.size(); i++){
        for(int j = 0; j< a[i].size(); j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


// DP solution of the same problem

// class Solution {
//     public:
//         vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//             map<int, vector<vector<int>>> mpp;
    
//             if(mpp.find(target) != mpp.end()) return mpp[target];
    
//             int n = candidates.size();
//             set<vector<int>> st;
    
//             if(target == 0) return {{}};
//             if(target < 0) return {};
    
//             for(int i = 0; i< n; i++){
//                 int rem = target - candidates[i];
    
//                 vector<vector<int>> temp = combinationSum(candidates, rem);
                
//                 for(int j = 0; j< temp.size(); j++){
//                     vector<int> newWay = {candidates[i]};
//                     newWay.insert(newWay.end(), temp[j].begin(), temp[j].end());
    
//                     sort(newWay.begin(), newWay.end());
//                     st.insert(newWay);
//                 }
//             }
//             vector<vector<int>> arr(st.begin(), st.end());
//             mpp[target] = arr;
//             return arr;
//         }
//     };
