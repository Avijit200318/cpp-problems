#include<bits/stdc++.h>
using namespace std;

// class Solution
// {
//     public:
//     vector <int> twoSumElements(vector <int> arr, int k)
//     {
//         int n = arr.size();
//         vector <int> v;
//         for(int i = 0; i< n; i++)
//         {
//             for(int j = i+1; j< n; j++)
//             {
//                 int sum = arr[i] + arr[j];
//                 if(sum == k)
//                 {
//                     v.push_back(arr[i]);
//                     v.push_back(arr[j]);
//                     break;
//                 }
//             }
//         }
//         return v;
//     }
// };
// the time complexty is o(n^2).

class Solution
{
    public:
    vector <int> twoSumElements(vector <int> arr, int k)
    {
        map <int, int> m;
        vector <int> v;
        int more = 0;
        for(int i = 0; i< arr.size(); i++)
        {
            more = k - arr[i];
            if(m.find(more) != m.end())
            {
                v.push_back(arr[i]);
                v.push_back(more);
            }
            m[arr[i]] = more;
        }
        return {-1, -1};
    }
};
// the time complexity of this code is o(nlogN)+o(n).

int main()
{
    vector <int> v = {2, 6, 5, 8, 11};
    int k = 9;
    Solution s;
    vector <int> a = s.twoSumElements(v, k);
    for(auto p : a)
    {
        cout<< p<< " ";
    }
    return 0;
}