// maximum subarray sum of a circular array

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // int circularSubarraySum(vector<int> arr)
    // {
    //     int n = arr.size();
    //     int ans = 0;
    //     int currSum = 0;
    //     for(int i = 0; i< n; i++){
    //         currSum = 0;
    //         for(int j = 0; j< n; j++){
    //             int idx = (i + j) % n;
    //             currSum += arr[idx];
    //             ans = max(ans, currSum);
    //         }
    //     }
    //     return ans;
    // }
    // this is the brute force solution


    // int circularSubarraySum(vector<int> arr)
    // {
    //     int n = arr.size();
    //     int suffixSum = arr[n-1];

    //     vector<int> suffixArray(n, 0);
    //     suffixArray[n-1] = arr[n-1];

    //     for(int i = n-2; i >= 0; i--){
    //         suffixSum += arr[i];
    //         suffixArray[i] = max(suffixSum, suffixArray[i+1]);
    //     }
    //     // done calculation for suffix sum array

    //     int circularSum = arr[0], normalSum = arr[0];
    //     int currSum = 0, prefix = 0;

    //     for(int i = 0; i< n; i++){
    //         prefix += arr[i];

    //         currSum = max(prefix, arr[i]);
    //         normalSum = max(currSum, arr[i]);

    //         circularSum = max(circularSum, prefix + suffixArray[i+1]);
    //     }
    //     return circularSum;
    // }
    // this is the better solution


    int circularSubarraySum(vector<int> arr)
    {
        int n = arr.size();
        int minSum = 0, sum = 0, normalSum = 0;
        
        for(int i = 0; i< n; i++){
            sum += arr[i];
            normalSum += arr[i];
            if(minSum > sum){
                minSum = sum;
            }
            
            if(sum > 0){
                sum = 0;
            }
        }
        cout<<normalSum<<endl;
        cout<<minSum<<endl;
        return (normalSum - minSum);
    }
};

int main()
{
    Solution s;
    vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
    // ans 22
    // vector<int> arr = {10, -3, -4, 7, 6, 5, -4, -1};
    // ans 23
    // vector<int> arr = {-1, 40, -14, 7, 6, 5, -4, -1};
    // ans 52
    int a = s.circularSubarraySum(arr);
    cout << "the answer is " << a;
    return 0;
}
