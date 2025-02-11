// Find H-Index
// Given an integer array citations[], where citations[i] is the number of citations a researcher received for the ith paper. The task is to find the H-index.

// H-Index is the largest value such that the researcher has at least H papers that have been cited at least H times.

// Examples:

// Input: citations[] = [3, 0, 5, 3, 0]
// Output: 3
// Explanation: There are at least 3 papers (3, 5, 3) with at least 3 citations.

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // int hIndex(vector<int> arr){
    //     // sort the array in descrising order
    //     sort(arr.begin(), arr.end());
    //     reverse(arr.begin(), arr.end());

    //     // then check if arr[i] > i means we have atleast hth paper
    //     for(int i = 0; i< arr.size(); i++){
    //         if(arr[i] <= i) return i;
    //     }
    // }
    // o(nlog(n) + o(n)) is the timecomplexity of this approach

    int hIndex(vector<int> arr){
        int n= arr.size();
        vector<int> hash(n+1, 0);

        for(int i = 0; i< n; i++){
            if(arr[i] >= n){
                hash[n]++;
            }
            else{
                hash[arr[i]]++;
            }
        }

        int sum = 0;
        for(int i = n; i>= 0; i--){
            sum += hash[i];
            if(i <= sum) return i;
        }
        return 0;
    }
};

int main(){
    Solution s;
    int a = s.hIndex({3, 0, 5, 3, 0});
    // int a = s.hIndex({5, 1, 2, 4, 1});
    // int a = s.hIndex({0, 0});
    cout<<"the answer is: "<<a;
    return 0;
}
