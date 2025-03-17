// {3, 1, 2} => {3}, {2}, {1}, {}, {3, 1}, {3, 2}, {1, 2}, {3, 1, 2}

#include<bits/stdc++.h>
using namespace std;

void subsequence(vector<int> arr, int idx, int n, vector<vector<int>> &ans, vector<int> &current){
    if(idx == n){
        ans.push_back(current);
        return;
    }

    current.push_back(arr[idx]);
    subsequence(arr, idx+1, n, ans, current);

    // now remvoe the previous step
    current.pop_back();
    subsequence(arr, idx+1, n, ans, current);
}

int main(){
    vector<int> arr = {3, 1, 2};
    vector<vector<int>> ans;
    vector<int> current;

    subsequence(arr, 0, arr.size(), ans, current);

    for(int i = 0; i< ans.size(); i++){
        for(int j = 0; j< ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
