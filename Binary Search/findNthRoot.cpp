#include<bits/stdc++.h>
using namespace std;

// class Solution
// {
//     public:
//     int multiplierFunction(int i , int n)
//     {
//         int ans = 1;
//         for(int j = 0; j < n; j++)
//         {
//             ans = ans * i;
//         }
//         return ans;
//     }
//     int findNthRoot(int n, int m)
//     {
//         for(int i = 1; i<= m; i++)
//         {
//             if(multiplierFunction(i, n) == m)
//             {
//                 return i;
//             }
//             else if(multiplierFunction(i, n) > m)
//             {
//                 return -1;
//             }
//         }
//         return -1;
//     }
// };
// this is the brute force solution whose time complexity is o(n*m).


class Solution
{
    public:
    int multiplierFunction(int i , int n)
    {
        int ans = 1;
        for(int j = 0; j < n; j++)
        {
            ans = ans * i;
        }
        return ans;
    }
    int findNthRoot(int n, int m)
    {
        int low = 1, high = m;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(multiplierFunction(mid, n) == m)
            {
                return mid;
            }
            else if(multiplierFunction(mid, n) > m)
            {
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return -1;
    }
};

int main()
{
    int m = 27, n = 3;
    // int m = 69, n = 3;
    Solution s;
    int a = s.findNthRoot(n, m);
    cout<< a;
    return 0;
}