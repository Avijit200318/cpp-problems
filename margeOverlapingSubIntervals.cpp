#include<bits/stdc++.h>
using namespace std;

// class Solution{
//     public:
//     vector<vector<int>> mergeOverlappingSubIntervals(vector<vector<int>> arr)
//     {
//         int n = arr.size();
//         vector<vector<int>> ans;
//         sort(arr.begin(), arr.end());
//         for(int i = 0; i< n; i++)
//         {
//             int start = arr[i][0];
//             int end = arr[i][1];
//             if(!ans.empty() && end <= ans.back()[1])
//             {
//                 continue;
//             }
//             for(int j = i+1; j< n; j++)
//             {
//                 if(arr[j][0] < end)
//                 {
//                     end = max(end, arr[j][1]);
//                 }
//                 else{
//                     break;
//                 }
//             }
//             ans.push_back({start,end});
//         }
//         return ans;
//     }
// };
// this is the brute force solution whose time complexity is o(2n)+o(nlogn).

// class Solution{
//     public:
//     vector<vector<int>> mergeOverlappingSubIntervals(vector<vector<int>> arr)
//     {
//         int n = arr.size();
//         sort(arr.begin(), arr.end());
//         vector<vector<int>> ans;
//         for(int i = 0; i< n; i++)
//         {
//             if(ans.empty() || arr[i][0] > ans.back()[1])
//             {
//                 ans.push_back(arr[i]);
//             }
//             else{
//                 ans.back()[1] = max(ans.back()[1], arr[i][1]);
//             }
//         }
//         return ans;
//     }
// };
// this is the better and optimal solution whose time complexity is o(nlogn)+o(n) and space o(n).


int main()
{
    vector<vector<int>> v = {{1,3}, {2,4}, {2,6}, {8,9}, {8, 10}, {9, 11},{15,18},{16,17}};
    Solution s;
    vector<vector<int>> a = s.mergeOverlappingSubIntervals(v);
    int n = a.size();
    for(int i= 0; i< n; i++)
    {
        for(int j = 0; j< 2; j++)
        {
            cout<< a[i][j]<< " ";
        }
        cout<<endl;
    }
    return 0;
}