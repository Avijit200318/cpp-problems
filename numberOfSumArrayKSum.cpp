#include<bits/stdc++.h>
using namespace std;

// class Solution{
//     public:
//     int numberOfSubArrayEqulToKSum(vector<int> arr, int k)
//     {
//         int n = arr.size();
//         int sum = 0;
//         int count = 0;
//         for(int i = 0; i<n; i++)
//         {
//             for(int j = i; j< n; j++)
//             {
//                 sum = 0;
//                 for(int k = i; k <= j; k++)
//                 {
//                     sum += arr[k];
//                 }
//                 if(k == sum)
//                 {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };
// this is the bruteforce solution whose timecomplexity is o(n^3).

// class Solution{
//     public:
//     int numberOfSubArrayEqulToKSum(vector<int> arr, int k)
//     {
//         int n = arr.size();
//         int sum = 0;
//         int count = 0;
//         for(int i = 0; i<n; i++)
//         {
//             sum = 0;
//             for(int j = i; j<n; j++)
//             {
//                 sum += arr[j];
//                 if(sum == k)
//                 {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };
// the is the better solution and the time complexity of this code is o(n^2).


class Solution{
    public:
    int numberOfSubArrayEqulToKSum(vector<int> arr, int k)
    {
        int n = arr.size();
        int preSum = 0;
        int count = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        // this help us to count when sum = 3 and rem = 3-3 = 0 so it help to increase the count by 1.
        for(int i = 0; i< n; i++)
        {
            preSum += arr[i];
            int rem = preSum - k;
            count += mpp[rem];
            mpp[preSum] += 1;
        }
        return count;
    }
};
// this is the optimal solution and the time complexity is o(n * n) or o(n*logn) and the space complexity is o(n).


int main()
{
    vector<int> v = {1,2,3,-3,1,1,1,4,2,-3};
    int k = 3;
    Solution s;
    int a = s.numberOfSubArrayEqulToKSum(v, k);
    cout<< a;
    return 0;
}