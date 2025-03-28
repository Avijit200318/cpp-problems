// Permutation Sequence

// for the brute forece solution you can generate all the permutation in sorted order then you can find kth element

// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.


// Example 1:

// Input: n = 3, k = 3
// Output: "213"

// *********brueforce solution**********
#include<bits/stdc++.h>
using namespace std;

void solve(int idx, int n, string &arr, vector<string> &ans){
    if(idx == n){
        ans.push_back(arr);
        return;
    }

    for(int i = idx; i< n; i++){
        swap(arr[idx], arr[i]);
        solve(idx+1, n, arr, ans);
        swap(arr[idx], arr[i]);
    }
}

string kthPermutation(int n, int k){
    string arr;
    for(int i = 1; i<= n; i++){
        arr.push_back(i + '0');
    }

    vector<string> ans;
    solve(0, n, arr, ans);

    return ans[k-1];
}

int main(){
    string a = kthPermutation(3, 3);
    cout<<"the answer is: "<<a;
    return 0;
}


// this will take almost time o(n!)


// this one is optimal solution
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> arr;

        for(int i = 1; i< n; i++){
            // we are running the loop one less time because we are calculating the factorial.
            fact = fact * i;

            arr.push_back(i);
        }
        arr.push_back(n);
        // push back the last element inside the array.

        string ans = "";
        k = k-1;
        // decrease the value of k by 1 because we are counting from 0th index array so for 4 element we can create 24 permutation but the last permutation will be 23th permutation.

        while(true){
            ans = ans + to_string(arr[k / fact]);
            arr.erase(arr.begin() + (k / fact));
            // erase the element from the array

            if(arr.size() == 0) break;

            k = k % fact;
            // change kth new value

            fact = fact / arr.size();
            // change the factorial value because for n = 4 it will be 6 but when n = 3 it will be 2 so divide it with array size
        }
        return ans;
    }
};
