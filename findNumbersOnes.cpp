// find the number that appear in only one times in an array.all the other value is occur twise or even number of times.

#include<bits/stdc++.h>
using namespace std;

// brute force solution o(n^2).

// class Solution
// {
//     public:
//     int numberOnlyOnceApear(vector <int> arr)
//     {
//         int maxi = INT_MIN;
//         int n = arr.size();
//         for(int i = 0; i< n; i++)
//         {
//             maxi = max(maxi, arr[i]);
//         }

//         int hash[maxi+1] = {0};
//         for(int i = 0; i< n; i++)
//         {
//             hash[arr[i]]++;
//         }
//         for(int i = 1; i<=maxi; i++)
//         {
//             if(hash[i] == 1)
//             {
//                 return arr[i];
//             }
//         }
//         return -1;
//     }
// };

// the time complexity of this code is o(3n). better solution. but there is an problem if the input is very big like 10^5 then we did not use this method.


// class Solution
// {
//     public:
//     int numberOnlyOnceApear(vector <int> arr)
//     {
//         map <long, int> m;
//         // the time complexity in insert o(nlogm). m = size of the map.
//         unordered_map <long, int> um;
//         // the time complexity in unorder map is o(1) , worst cast o(n).
//         for(int i = 0; i< arr.size(); i++)
//         {
//             um[arr[i]]++;
//         }
//         for(auto a : um)
//         {
//             if(a.second == 1)
//             {
//                 return a.first;
//             }
//         }
//         return -1;
//     }
// };

// the time complexity of this code is o(n + n/2=m), m= mapsize. if the values are critical then we use ordermap. so in this case the time complexity become o(n/2+1)+o(nlogm).Another better solution.

class Solution
{
    public:
    int numberOnlyOnceApear(vector <int> arr)
    {
        int xor1 = 0;
        for(int i = 0; i< arr.size(); i++)
        {
            xor1 = xor1 ^ arr[i];
        }
        return xor1;
    }
};
// this is the optimal solution whose time complexity is o(n).

int main()
{
    vector <int> v = {1, 1, 2, 3, 3, 4, 4};
    Solution s;
    int a = s.numberOnlyOnceApear(v);
    cout<< a;
    return 0;
}
