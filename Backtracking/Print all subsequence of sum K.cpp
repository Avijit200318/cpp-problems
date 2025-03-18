#include<bits/stdc++.h>
using namespace std;

void subSequence(vector<int> &arr, int idx, int n, int target, int sum, vector<vector<int>> &ans, vector<int> &current){
    if(idx == n){
        if(sum == target){
            ans.push_back(current);
        }
        return;
    }

    current.push_back(arr[idx]);
    subSequence(arr, idx+1, n, target, sum + arr[idx], ans, current);

    current.pop_back();

    subSequence(arr, idx+1, n, target, sum, ans, current);
}

int main(){
    vector<int> arr = {1, 2, 1};

    vector<vector<int>> ans;
    vector<int> current;

    subSequence(arr, 0, arr.size(), 3,0, ans, current);

    cout<<"The answer is: "<<endl;
    for(int i = 0; i< ans.size(); i++){
        for(int j = 0; j< ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
