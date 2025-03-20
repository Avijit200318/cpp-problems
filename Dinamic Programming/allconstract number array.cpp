#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    // {
    //     set<vector<int>> st;
    //     int n = candidates.size();

    //     if (target == 0)
    //         return {{}};

    //     if(target < 0) return {};

    //     for (int i = 0; i < n; i++)
    //     {
    //         int rem = target - candidates[i];

    //         vector<vector<int>> temp = combinationSum(candidates, rem);
    //             for(int j = 0; j< temp.size(); j++){
    //                 vector<int> newWay = {candidates[i]};
    //                 newWay.insert(newWay.end(), temp[j].begin(), temp[j].end());
    //                 sort(newWay.begin(), newWay.end());
    //                 st.insert(newWay);
    //             }
    //     }
    //     return vector<vector<int>>(st.begin(), st.end());
    // }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        map<int, vector<vector<int>>> mpp;

        if(mpp.find(target) != mpp.end()) return mpp[target];

        set<vector<int>> st;
        int n = candidates.size();

        if (target == 0)
            return {{}};

        if(target < 0) return {};

        for (int i = 0; i < n; i++)
        {
            int rem = target - candidates[i];

            vector<vector<int>> temp = combinationSum(candidates, rem);
                for(int j = 0; j< temp.size(); j++){
                    vector<int> newWay = {candidates[i]};
                    newWay.insert(newWay.end(), temp[j].begin(), temp[j].end());
                    sort(newWay.begin(), newWay.end());
                    st.insert(newWay);
                }
        }
        vector<vector<int>> arr(st.begin(), st.end());
        mpp[target] = arr;
        return arr;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {2, 3, 6, 7};
    vector<vector<int>> a = s.combinationSum(arr, 7);
    cout<<"the answer is : "<<endl;
    for (int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j< a[i].size(); j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
