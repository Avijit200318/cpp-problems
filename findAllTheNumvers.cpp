// find all the number disapear in the array
// input = [4,3,2,7,8,2,3,1] n = 8
// output = [5,6]
#include<bits/stdc++.h>
using namespace std;

// class Solution
// {
//     public:
//     vector<int> findAllNumbers(vector<int> arr)
//     {
//         int n = arr.size();
//         map<int, int> mpp;
//         vector<int> res;
//         for(int i = 0; i< n; i++)
//         {
//             mpp[arr[i]] += 1;
//         }
//         for(int i = 1; i< n+1; i++)
//         {
//             if(mpp[i] == 0)
//             {
//                 res.push_back(i);
//             }
//         }
//         return res;
//     }
// };
// this is the better solution whose time complexity is o(nlogn)+o(n)+o(n)

class Solution
{
    public:
    vector<int> findAllNumbers(vector<int> arr)
    {
        int n = arr.size();
        vector<int> res;
        for(int i = 0; i< n; i++)
        {
            int idx = abs(arr[i]) -1;
            if(arr[idx] > 0)
            {
                arr[idx] = -arr[idx];
            }
        }
        for(int i = 0; i< n; i++)
        {
            if(arr[i] > 0)
            {
                res.push_back(i+1);
            }
        }
        return res;
    }
};
// this is the optimal solution whose time complexity is o(2n). and space complexity is o(1).

int main()
{
    vector<int> v = {4,3,2,7,8,2,3,1};
    Solution s;
    vector<int> a = s.findAllNumbers(v);
    for(auto it : a)
    {
        cout<< it<< " ";
    }
    return 0;
}