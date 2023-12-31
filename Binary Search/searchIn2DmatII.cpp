/*Search in 2d matrix II*/

#include<bits/stdc++.h>
using namespace std;

// the brute force solution is o(m+n)+o((m+n)log(m+n))+o(m+n)

// class Solution{
//     public:
//     int binarySearch(vector<int> arr, int target)
//     {
//         int n = arr.size();
//         int low = 0, high = n-1;
//         while(low <= high)
//         {
//             int mid = (low + high)/2;
//             if(arr[mid] == target)
//             {
//                 return mid;
//             }
//             else if(arr[mid] > target)
//             {
//                 high = mid - 1;
//             }
//             else{
//                 low = mid + 1;
//             }
//         }
//         return -1;
//     }
//     vector<int> searchRowColmn(vector<vector<int>> arr, int target)
//     {
//         int n = arr.size(), m = arr[0].size();
//         for(int i = 0; i< n; i++)
//         {
//             int col = binarySearch(arr[i], target);
//             if(col != -1)
//             {
//                 return {i, col};
//             }
//         }
//         return {-1, -1};
//     }
// };
// this is the better solution whose time complexity is o(nlogn * n).

class Solution{
    public:
    vector<int> searchRowColmn(vector<vector<int>> arr, int target)
    {
        int n = arr.size(), m = arr[0].size();
        int row = 0, col = m -1;
        while(row < n && col >= 0)
        {
            if(arr[row][col] == target)
            {
                return {row, col};
            }
            else if(arr[row][col] < target)
            {
                row++;
            }
            else{
                col--;
            }
        }
        return {-1, -1};
    }
};
// this is the optimal solution whose time complexity o(m+n).

int main()
{
    vector<vector<int>> arr = {{1,4,7, 11,15}, {2,5,8,12,19}, {3,6,9,16,22}, {10,13,14,17,24}, {18,21,23,26,30}};
    Solution s;
    vector<int> ans = s.searchRowColmn(arr, 14);
    for(auto it: ans)
    {
        cout<< it << " ";
    }
    return 0;
}