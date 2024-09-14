#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // vector<int> howSum(int target, vector<int> arr){
    //     if(target == 0) return {};

    //     if(target < 0) return {-1};

    //     for(int i = 0; i< arr.size(); i++){
    //         int rem = target - arr[i];
    //         vector<int> temp = howSum(rem, arr);
    //         if(temp.size() == 0 || temp[0] != -1){
    //             temp.push_back(arr[i]);
    //             return temp;
    //         }
    //     }
    //     return {-1};
    // }

    map<int, vector<int>> mpp;
    vector<int> howSum(int target, vector<int> arr){
        if(mpp.find(target) != mpp.end()){
            return mpp[target];
        }

        if(target == 0) return {};

        if(target < 0) return {-1};

        for(int i = 0; i< arr.size(); i++){
            int rem = target - arr[i];
            vector<int> temp = howSum(rem, arr);
            if(temp.size() == 0 || temp[0] != -1){
                temp.push_back(arr[i]);
                mpp[target] = temp;
                return mpp[target];
            }
        }
        mpp[target] = {-1};
        return {-1};
    }
};

int main(){
    Solution s;
    // vector<int> a = s.howSum(7, {3, 4, 7, 8});
    // vector<int> a = s.howSum(7, {2, 4});
    // vector<int> a = s.howSum(8, {2, 3, 5});
    vector<int> a = s.howSum(300, {7, 14});
    for(int i = 0; i< a.size(); i++){
        cout<< a[i]<< " ";
    }
    return 0;
}
