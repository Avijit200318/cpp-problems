#include <bits/stdc++.h>
using namespace std;

// class Solution{
//     public:
//     vector<vector<int>> fourSum(vector<int> arr, int k)
//     {
//         int n = arr.size();
//         set<vector<int>> st;
//         for(int i = 0; i< n; i++)
//         {
//             for(int j = i+1; j< n; j++)
//             {
//                 for(int k = j+1; k < n; k++)
//                 {
//                     for(int l = k+1; l < n; l++)
//                     {
//                         if(arr[i]+arr[j]+arr[k]+arr[l] == k)
//                         {
//                             vector<int> temp = {arr[i], arr[j], arr[k],arr[l]};
//                             sort(temp.begin(), temp.end());
//                             st.insert(temp);
//                         }
//                     }
//                 }
//             }
//         }
//         vector<vector<int>> res(st.begin(), st.end());
//     }
// };
// broute force solution whose time complexity is o(n^4).


// class Solution
// {
// public:
//     vector<vector<int>> fourSum(vector<int> arr, int target)
//     {
//         int n = arr.size();
//         set<vector<int>> st;
//         for (int i = 0; i <n; i++)
//         {
//             for (int j = i + 1; j <n; j++)
//             {
//                 set<int> hash;
//                 for (int k = j + 1; k <n; k++)
//                 {
//                     int sum = arr[i] + arr[j]+ arr[k];
//                     int fourth = target - sum;
//                     if (hash.find(fourth) != hash.end())
//                     {
//                         vector<int> temp = {arr[i], arr[j], arr[k], fourth};
//                         sort(temp.begin(), temp.end());
//                         st.insert(temp);
//                     }
//                     hash.insert(arr[k]);
//                 }
//             }
//         }
//         vector<vector<int>> res(st.begin(), st.end());
//         return res;
//     }
// };
// this is the better solution whose time complexity is o(n^3)+o(nlogn) and space o(n)+o(to store 4 elements).

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> arr, int target)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        for(int i = 0; i< n; i++)
        {
            for(int j = i+1; j< n; j++)
            {
                if(j!=i+1 && arr[j] == arr[j-1])
                {
                    continue;
                }
                int k = j+1;
                int l = n-1;
                while(k < l)
                {
                    int sum = arr[i]+arr[j];
                    sum += (arr[k]+arr[l]);
                    if(sum < 0)
                    {
                        k++;
                    }
                    else if(sum > 0)
                    {
                        l--;
                    }
                    else{
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(arr[k] == arr[k-1] && k < l)
                            k++;
                        while(arr[l]==arr[l+1] && k < l)
                            l--;
                    }
                }
            }
        }
        return ans;
    }
};
// this is optimal solution whose time complexity is o(n^n)+o(nlogn) and space complexity is O(4th elment store).
int main()
{
    vector<int> v = {1, 0, -1, 0, -2, 2};
    cout<< "the code is running"<<endl;
    Solution s;
    int k = 0;
    vector<vector<int>> a = s.fourSum(v, k);
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