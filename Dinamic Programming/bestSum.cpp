#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    unordered_map<int, vector<int>> mpp;
    
    // vector<int> bestSum(int target, vector<int> arr){
    //     if(target == 0) return {};
    //     if(target < 0) return {-1};

    //     int n = arr.size();
    //     vector<int> shortestArray = {-1};

    //     for(int i = 0; i< n; i++){
    //         int rem = target - arr[i];
    //         vector<int> temp = bestSum(rem, arr);
    //         if(temp.size() == 0 || temp[0] != -1){
    //             temp.push_back(arr[i]);
    //             if(shortestArray[0] == -1 || temp.size() < shortestArray.size()){
    //                 shortestArray = temp;
    //             }
    //         }
    //     }
    //     return shortestArray;
    // }

    vector<int> bestSum(int target, vector<int> arr){
        if(mpp.find(target) != mpp.end()) return mpp[target];
        if(target == 0) return {};
        if(target < 0) return {-1};

        int n = arr.size();
        vector<int> shortestArray = {-1};

        for(int i = 0; i< n; i++){
            int rem = target - arr[i];
            vector<int> temp = bestSum(rem, arr);
            if(temp.size() == 0 || temp[0] != -1){
                temp.push_back(arr[i]);
                if(shortestArray[0] == -1 || temp.size() < shortestArray.size()){
                    shortestArray = temp;
                }
            }
        }
        mpp[target] = shortestArray;
        return shortestArray;
    }
};

int main(){
    Solution s;
    // vector<int> arr = {66, 26, 18, 55, 65, 50, 60, 20, 78, 75, 24};
    // vector<int> a = s.bestSum(455, arr);
    // vector<int> a = s.bestSum(7, {5,3, 4, 7});
    vector<int> a = s.bestSum(100, {1,2, 5,25});

    cout<<"The answer is: "<<endl;
    for(int i = 0; i< a.size(); i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
