// best sum
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // vector<vector<string>> allConstruct(string target, vector<string> arr)
    // {
    //     if(target == "") return {{}};

    //     vector<vector<string>> res;

    //     for(int i = 0; i< arr.size(); i++){
    //         if(target.substr(0, arr[i].size()) == arr[i]){
    //             string rem = target.substr(arr[i].size());
    //             vector<vector<string>> temp = allConstruct(rem, arr);
    //             // traverse the new vector {{}}
    //             for(int j = 0; j< temp.size(); j++){
    //                 vector<string> newWay = {arr[i]};
    //                 newWay.insert(newWay.end(), temp[j].begin(), temp[j].end());
    //                 res.push_back(newWay);
    //             }
    //         }
    //     }
    // return res;
    // }

    map<string, vector<vector<string>>> mpp;
    vector<vector<string>> allConstruct(string target, vector<string> arr)
    {
        if(mpp.find(target) != mpp.end()) return mpp[target];

        if(target == "") return {{}};

        vector<vector<string>> res;

        for(int i = 0; i< arr.size(); i++){
            if(target.substr(0, arr[i].size()) == arr[i]){
                string rem = target.substr(arr[i].size());
                vector<vector<string>> temp = allConstruct(rem, arr);
                for(int j = 0; j< temp.size(); j++){
                    vector<string> newWay = {arr[i]};
                    newWay.insert(newWay.end(), temp[j].begin(), temp[j].end());
                    res.push_back(newWay);
                }
            }
        }
        mpp[target] = res;
        return res;
    }
};

int main(){
    Solution s;
    // vector<vector<string>> a = s.allConstruct("purple", {"purp", "p", "ur", "le", "purpl"});
    // vector<vector<string>> a = s.allConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"});
    vector<vector<string>> a = s.allConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"});
    // vector<vector<string>> a = s.allConstruct("eeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"});

    for(int i = 0; i< a.size(); i++){
        for(int j = 0; j< a[i].size(); j++){
            cout<< a[i][j]<< " ";
        }
        cout<< endl;
    }
    return 0;
}
