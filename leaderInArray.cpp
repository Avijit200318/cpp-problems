#include<bits/stdc++.h>
using namespace std;

// class Solution
// {
//     public:
//     vector <int> leaderInAArray(vector <int> arr)
//     {
//         int n = arr.size();
//         vector <int> v;
//         for(int i = 0; i< n; i++)
//         {
//             int flag = true;
//             for(int j = i+1; j< n; j++)
//             {
//                 if(arr[i] < arr[j])
//                 {
//                     flag = false;
//                     break;
//                 }
//             }
//             if(flag == true)
//             {
//                 v.push_back(arr[i]);
//             }
//         }
//         return v;
//     }
// };
// this is the bruteforce solution whose time complexity is o(N^2).

class Solution
{
    public:
    vector <int> leaderInAArray(vector <int> arr)
    {
        int n = arr.size();
        vector <int> v;
        int maxi = INT_MIN;
        for(int i = n-1; i>= 0; i--)
        {
            if(maxi < arr[i])
            {
                maxi = arr[i];
                v.push_back(arr[i]);
            }
        }
        return v;
    }
};

// this is the optimal solution whose time complexity is o(N) and space complexity is o(n).

int main()
{
    vector <int> v = {10, 22, 12, 3, 0, 6};
    Solution s;
    vector <int> a = s.leaderInAArray(v);
    for(auto it : a)
    {
        cout<< it<< " ";
    }
    return 0;
}