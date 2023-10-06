#include<bits/stdc++.h>
using namespace std;

// class Solution
// {
//     public:
//     bool toSum(vector <int> arr, int k)
//     {
//         int n = arr.size();
//         for(int i = 0; i< n; i ++)
//         {
//             for(int j = 0;j < n; j++)
//             {
//                 if(arr[i] + arr[j] == k)
//                     return true;
//             }
//         }
//         return false;
//     }
// };
// brute force solution whose time complexity is o(n^2).

// class Solution
// {
//     public:
//     bool toSum(vector <int> arr, int k)
//     {
//         map <int, int> m;
//         int sum = 0, more = 0;
//         for(int i = 0; i< arr.size(); i++)
//         {
//             more = k - arr[i];
//             if(m.find(more) != m.end())
//             {
//                 return true;
//             }
//             m[arr[i]] = more;
//         }
//         return false;
//     }
// };
// the time complexity of this code is o(nlonN)+o(n) or o(n)+o(n)[for unorder map].

class Solution
{
    public:
    bool toSum(vector <int> arr, int k)
    {
        int left = 0, right = arr.size() -1;
        sort(arr.begin(), arr.end());
        while(left < right)
        {
            int sum = arr[left] + arr[right];
            if(sum == k)
                return true;
            else if(sum < k)
                left++;
            else
                right--;
        }
        return false;
    }
};
// this is two pointer method or gready method whose time complexiy is o(n).

int main()
{
    vector <int> v = {2, 6, 5, 8, 11};
    int k = 14;
    Solution s;
    bool a = s.toSum(v, k);
    if(a == 1)
        cout<< "true";
    else
        cout<< "false";
    return 0;
}
