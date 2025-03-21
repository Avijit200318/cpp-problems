// You are given an array 'nums' of ‘n’ integers.



// Return all subset sums of 'nums' in a non-decreasing order.



// Note:
// Here subset sum means sum of all elements of a subset of 'nums'. A subset of 'nums' is an array formed by removing some (possibly zero or all) elements of 'nums'.


// For example
// Input: 'nums' = [1,2]

// Output: 0 1 2 3


#include<bits/stdc++.h>
using namespace std;

void solve(int idx, int sum, int n, vector<int> &arr, vector<int> &ans){
    if(idx == n){
        ans.push_back(sum);
        return;
    }

    solve(idx+1, sum+arr[idx], n, arr, ans);

    solve(idx+1, sum, n, arr, ans);
}

vector<int> sumOfSubsets(vector<int> arr){
    int n = arr.size();
    vector<int> ans;

    solve(0, 0, n, arr, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> arr = {3, 2, 1};
    vector<int> a = sumOfSubsets(arr);
    cout<<"The answer is"<<endl;
    for(int i = 0; i< a.size(); i++){
        cout<<a[i]<<" ";
    }
    return 0;
}

// time complexity is o(2^n)
