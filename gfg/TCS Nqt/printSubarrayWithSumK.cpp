// print the sumarrays with sum k

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
//     vector<int> helper(int start, int end, vector<int> arr, int n){
//         vector<int> ans;
//         for(int i = start; i<= end; i++){
//             ans.push_back(arr[i]);
//         }
//         return ans;
//     }

//     vector<vector<int>> subarray(vector<int> arr, int target){
//         int n = arr.size();
//         int sum = 0;
//         vector<vector<int>> res;
//         for(int i = 0; i< n; i++){
//             sum = 0;
//             for(int j = i; j < n; j++)
//             {
//                 sum += arr[j];
//                 if(sum == target){
//                     vector<int> temp = helper(i, j, arr, n);
//                     res.push_back(temp);
//                 }
//             }
//         }
//         return res;
//     }

vector<int> helper(int start, int end, vector<int> arr, int n){
        vector<int> ans;
        for(int i = start; i<= end; i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }

    vector<vector<int>> subarray(vector<int> arr, int target){
        int n = arr.size();
        map<int, int> mpp;
        int sum = 0;
        vector<vector<int>> res;
        for(int i = 0; i< n; i++){
            sum += arr[i];
            if(sum == target){
                vector<int> temp = helper(0, i, arr, n);
                res.push_back(temp);
            }
            int rem = sum - target;
            if(mpp.find(rem) != mpp.end()){
                vector<int> temp = helper(mpp[rem]+1, i, arr, n);
                res.push_back(temp);
            }

            if(mpp.find(sum) == mpp.end()){
                mpp[sum] = i;
            }
        }
        return res;
    }
};


int main(){
    vector<int> arr = {3, 4, -7, 1, 3, 3, 1, -4};
    Solution s;
    vector<vector<int>> a = s.subarray(arr, 7);
    for(int i = 0; i< a.size(); i++){
        for(int j = 0; j< a[i].size(); j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
