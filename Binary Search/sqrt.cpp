#include<bits/stdc++.h>
using namespace std;

// class Solution
// {
//     public:
//     int squrt(int k)
//     {
//         int ans = 0;
//         for(int i = 1; i<= k; i++)
//         {
//             if(i * i <= k)
//             {
//                 ans = i;
//             }
//             else{
//                 break;
//             }
//         }
//         return ans;
//     }
// };
// this is the brute force solution whose time complexity is o(n) almost.
class Solution
{
    public:
    int squrt(int k)
    {
        int low = 1, high = k;
        int ans = 1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(mid * mid <= k)
            {
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    int v = 25;
    // int v = 49;
    // int v = 30;
    Solution s;
    int a = s.squrt(v);
    cout<< a;
    return 0;
}