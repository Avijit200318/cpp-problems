// best sum
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // int countNoCreate(string target, vector<string> arr){
    //     if(target == "") return 1;

    //     int count = 0;

    //     for(int i = 0; i< arr.size(); i++){
    //         if(target.substr(0, arr[i].size()) == arr[i]){
    //             string rem = target.substr(arr[i].size());
    //             count += countNoCreate(rem, arr);
    //         }
    //     }
    //     return count;
    // }

    map<string, int> mpp;
    int countNoCreate(string target, vector<string> arr){
        if(mpp.find(target) != mpp.end()) return mpp[target];
        if(target == "") return 1;

        int count = 0;

        for(int i = 0; i< arr.size(); i++){
            if(target.substr(0, arr[i].size()) == arr[i]){
                string rem = target.substr(arr[i].size());
                count += countNoCreate(rem, arr);
            }
        }
        mpp[target] = count;
        return count;
    }
};

int main(){
    Solution s;
    // int a = s.countNoCreate("purple", {"purp", "p", "ur", "le", "purpl"});
    // int a = s.countNoCreate("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"});
    // int a = s.countNoCreate("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"});
    int a = s.countNoCreate("eeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"});

    cout<< a;
    return 0;
}
