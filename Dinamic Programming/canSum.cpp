// we can use as many time of elements inside the array to generate the target
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    unordered_map<int, bool> mpp;
    // bool canSum(int target, vector<int> arr){
    //     if(target == 0) return true;
    //     if(target < 0) return false;

    //     int n = arr.size();

    //     for(int i = 0; i< n; i++){
    //         int rem = target - arr[i];

    //         if(canSum(rem, arr)){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    bool canSum(int target, vector<int> arr){
        if(mpp.find(target) != mpp.end()) return mpp[target];
        if(target == 0) return true;
        if(target < 0) return false;

        int n = arr.size();

        for(int i = 0; i< n; i++){
            int rem = target - arr[i];

            if(canSum(rem, arr)){
                mpp[target] = true;
                return true;
            }
        }
        mpp[target] = false;
        return false;
    }
};

int main(){
    Solution s;
    vector<int> arr = {66, 26, 18, 55, 65, 50, 60, 20, 78, 75, 24};
    int a = s.canSum(455, arr);
    cout<<"The answer is: "<<a;
    return 0;
}
