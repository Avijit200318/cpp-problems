/* Search the missing number in an array*/

#include<bits/stdc++.h>
using namespace std;

// class Solution
// {
//     public:
//     int missingNumber(vector <int> arr, int n)
//     {
//         int n1 = arr.size();
//         for(int i = 1; i<= n; i++ )
//         {
//             int flag = 0;
//             for(int j = 0; j< n1; j++)
//             {
//                 if(arr[j] == i)
//                 {
//                     flag = 1;
//                     break;
//                 }
//             }
//             if(flag == 0)
//             {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

// this is the brute force solution. whose time complexity is o(n^2). it may stuck in infinite loop.

// class Solution
// {
//     public:
//     int missingNumber(vector <int> arr, int n)
//     {
//         int n1 = arr.size();
//         int hash[n+1] = {0};
//         for(int i = 0; i< n1; i++)
//         {
//             hash[arr[i]]++;
//         }
//         for(int i = 1; i< n; i++)
//         {
//             if(hash[i] == 0)
//             {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

// this is better method the time complexity is o(n1+n) or o(2n).

// class Solution
// {
//     public:
//     int missingNumber(vector <int> arr, int n)
//     {
//         int sum = n*(n+1)/2;
//         int addition = 0;
//         int n1 = arr.size();
//         for(int i = 0; i< n1; i++)
//         {
//             addition = addition + arr[i];
//         }
//         return sum - addition;
//     }
// };

// the time complexity of this code is o(n).but their is stil is a problem if the input is 10^5 then sum = almost 10^10 which we cannot store in int variable we need to use long.

class Solution
{
    public:
    int missingNumber(vector <int> arr, int n)
    {
        int xor1 = 0, xor2 = 0;
        int n1 = arr.size();
        for(int i = 0; i< n1; i++)
        {
            xor2 = xor2 ^ arr[i];
            xor1 = xor1 ^ (i+1);
        }
        xor1 = xor1 ^ n;
        // because inside the loop the xor1 one is goes to untill 4 in this case.
        return xor1 ^ xor2;
    }
};

// the time complexity of this code is o(n).So the sum and the xor method is the optimal method.

int main()
{
    vector <int> v = {1,2,4,5};
    int size = 5;
    Solution s;
    int a = s.missingNumber(v, size);
    cout<< a;
    return 0;
}
