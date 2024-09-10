#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // bool canSum(int target, vector<int> arr){
    //     if(target == 0) return true;

    //     if(target < 0 ) return false;
    //     int n = arr.size();
    //     for(int i = 0; i< n; i++){
    //         int rem = target - arr[i];
    //         if(canSum(rem, arr) == true){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    
    map<int, int> mpp;
    bool canSum(int target, vector<int> arr){
        if(mpp.find(target) != mpp.end()){
            return mpp[target];
        }

        if(target == 0) return true;

        if(target < 0 ) return false;
        int n = arr.size();
        for(int i = 0; i< n; i++){
            int rem = target - arr[i];
            if(canSum(rem, arr) == true){
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
    // int a = s.canSum(7, {3, 4, 7, 8});
    // int a = s.canSum(7, {2, 4});
    // int a = s.canSum(8, {2, 3, 5});
    int a = s.canSum(300, {7, 14});
    cout<< a;
    return 0;
}
