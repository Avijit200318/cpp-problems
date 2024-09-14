// best sum
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // bool canCreate(string target, vector<string> arr){
    //     if(target == "") return true;

    //     for(int i = 0; i< arr.size(); i++){
    //         if(target.substr(0, arr[i].size()) == arr[i]){
    //             string rem = target.substr(arr[i].size());
    //             if(canCreate(rem, arr) == true){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }

    map<string, bool> mpp;
    bool canCreate(string target, vector<string> arr){
        if(mpp.find(target) != mpp.end()){
            return mpp[target];
        }

        if(target == "") return true;

        for(int i = 0; i< arr.size(); i++){
            if(target.substr(0, arr[i].size()) == arr[i]){
                string rem = target.substr(arr[i].size());
                if(canCreate(rem, arr) == true){
                    mpp[target] = true;
                    return true;
                }
            }
        }
        mpp[target] = false;
        return false;
    }
};

int main(){
    Solution s;
    int a = s.canCreate("abcdef", {"ab", "abc", "cd", "def", "abcd"});
    // int a = s.canCreate("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"});
    // int a = s.canCreate("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"});
    // int a = s.canCreate("eeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"});

    cout<< a;
    return 0;
}
