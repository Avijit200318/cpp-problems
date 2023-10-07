#include<bits/stdc++.h>
using namespace std;

// class Solution
// {
//     public:
//     int maximumSubArraySum(vector <int> arr)
//     {
//         int n = arr.size();
//         int maxSum = INT_MIN, sum = 0;
//         for(int i = 0; i< n; i++)
//         {
//             for(int j = 0; j < n; j++)
//             {
//                 sum = 0;
//                 for(int k = i; k< j; k++)
//                 {
//                     sum += arr[k];
//                 }
//                 maxSum = max(sum, maxSum);
//             }
//         }
//         return maxSum;
//     }
// };
// this is the brute force solution whose time complexity is o(n^3).


// class Solution
// {
//     public:
//     int maximumSubArraySum(vector <int> arr)
//     {
//         int n = arr.size();
//         int maxSum = INT_MIN, sum = 0;
//         for(int i = 0; i< n; i++)
//         {
//             sum = 0;
//             for(int j = i; j < n; j++)
//             {
//                 sum += arr[j];
//                 maxSum = max(sum, maxSum);
//             }
//         }
//         return maxSum;
//     }
// };
// the time complexity of this code is o(n^2).

class Solution
{
    public:
    int maximumSubArraySum(vector <int> arr)
    {
        int n = arr.size();
        int sum = 0, maxSum = INT_MIN;
        for(int i = 0; i< n; i++)
        {
            sum += arr[i];
            if(sum < 0)
            {
                sum = 0;
            }
            if(sum > maxSum)
            {
                maxSum = sum;
            }
        }
        return maxSum;
    }
};

// this the optimal solution using khadam algo. the time complexity of this algo is o(n);

int main()
{
    vector <int> v = {-2, -2, 4, -1, -2, 1, 5, -3};
    Solution s;
    int a = s.maximumSubArraySum(v);
    cout<< a;
    return 0;
}