#include <bits/stdc++.h>
using namespace std;

// class Solution{
//     public:
//     vector<vector<int>> threeSum(vector<int> arr)
//     {
//         set<vector<int>> st;
//         int n = arr.size();
//         for(int i = 0; i< n; i++)
//         {
//             for(int j = i+1; j < n; j++)
//             {
//                 for(int k = j+1; k < n ;k++)
//                 {
//                     if(arr[i]+arr[j]+arr[k] == 0)
//                     {
//                         vector<int> temp = {arr[i], arr[j], arr[k]};
//                         sort(temp.begin(), temp.end());
//                         st.insert(temp);
//                     }
//                 }
//             }
//         }
//         vector<vector<int>> res({st.begin(), st.end()});
//         return res;
//     }
// };
// this is the bruteforce solution whose time complexity is o(n^3)+o(nlogn)+o(nlogn) and space is o(n).

// class Solution
// {
// public:
//     vector<vector<int>> threeSum(vector<int> arr)
//     {
//         set<vector<int>> st;
//         int n = arr.size();
//         for(int i = 0; i< n; i++)
//         {
//             set<int> hash;
//             for(int j = i+1; j< n; j++)
//             {
//                 int third = -(arr[i]+arr[j]);
//                 if(hash.find(third) != hash.end())
//                 {
//                     vector<int> temp = {arr[i], arr[j], third};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//                 hash.insert(arr[j]);
//             }
//         }
//         vector<vector<int>> res(st.begin(), st.end());
//         return res;
//     }
// };
// this is the better solution whose time complexity is o(n^2)*o(nlogn).

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> arr)
    {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for(int i = 0; i< n; i++)
        {
            if(i > 0 && arr[i] == arr[i-1])
            {
                continue;
            }
            int j = i+1;
            int k = n-1;
            while(j < k)
            {
                long long sum = arr[i]+ arr[j];
                sum += arr[k];
                if(sum < 0)
                {
                    j++;
                }
                else if(sum > 0)
                {
                    k--;
                }
                else{
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(arr[j] == arr[j-1] && j < k)
                        j++;
                    while(arr[k] == arr[k+1] && j < k)
                        k--;
                }
            }
        }
        return ans;
    }
};
// this is the optimal solution whose time complexity is o(n^n)+o(nlogn) and space complexity is o(n).

int main()
{
    vector<int> v = {-1, 0, 1, 2, -1, -4};
    Solution s;
    vector<vector<int>> a = s.threeSum(v);
    int n = a.size();
    int m = a[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}