#include<bits/stdc++.h>
using namespace std;

// class Solution
// {
//     public:
//     int countSubArrayWithXor(vector<int> arr, int target)
//     {
//         int n = arr.size();
//         int count = 0;
//         int xorVal = 0;
//         for(int i = 0; i< n; i++)
//         {
//             for(int j = i; j< n; j++)
//             {
//                 xorVal = 0;
//                 for(int k = i ; k <= j ;k++)
//                 {
//                     xorVal = xorVal ^ arr[k];
//                 }
//                 if(xorVal == target)
//                 {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };
// this is the broute force technique whose time complexity is o(n^3) and space complexity is o(1)

// class Solution
// {
//     public:
//     int countSubArrayWithXor(vector<int> arr, int target)
//     {
//         int n = arr.size();
//         int count = 0;
//         int xorVal = 0;
//         for(int i = 0; i< n; i++)
//         {
//             xorVal = 0;
//             for(int j = i; j< n; j++)
//             {
//                 xorVal = xorVal ^ arr[j];
//                 if(xorVal == target)
//                 {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };
// this is the better solution whose time complexity is o(n^2). and spcace complexity is o(1).

class Solution
{
    public:
    int countSubArrayWithXor(vector<int> arr, int target)
    {
        int n = arr.size();
        map<int, int> mpp;
        mpp[0] = 1;
        int count = 0;
        int xorVal = 0;
        for(int i = 0; i<n; i++)
        {
            xorVal = xorVal ^ arr[i];
            int x = target ^ xorVal;
            count += mpp[x];
            mpp[xorVal]++;
        }
        return count;
    }
};
// this is the optimal solution whose time complexity is o(n)+o(nlogn) and space complexity is o(n).

int main()
{
    vector<int> v = {4,2,2,6,4};
    int k = 6;
    Solution s;
    int a = s.countSubArrayWithXor(v, k);
    cout<< a;
    return 0;
}