#include<bits/stdc++.h>
using namespace std;

// using liner serach method we can get this is the bruteforce method time complexity is o(n).
// class Solution
// {
//     public:
//     int minimumValueInRotatedSortedArray(vector<int> arr)
//     {
//         int n = arr.size();
//         int low = 0, high = n-1;
//         int ans = INT_MAX;
//         while(low <= high)
//         {
//             int mid = (low + high)/2;
//             if(arr[low] <= arr[mid])
//             {
//                 ans = min(ans, arr[low]);
//                 low = mid + 1;
//             }
//             else{
//                 ans = min(ans, arr[mid]);
//                 high = mid - 1;
//             }
//         }
//         return ans;
//     }
// };
// this is the better solution whose time complexity is o(logn).
class Solution
{
    public:
    int minimumValueInRotatedSortedArray(vector<int> arr)
    {
        int n = arr.size();
        int low = 0, high = n-1;
        int ans = INT_MAX;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(arr[low] <= arr[high])
            {
                ans = min(ans, arr[low]);
                break;
            }
            if(arr[low] <= arr[mid])
            {
                ans = min(ans, arr[low]);
                low = mid + 1;
            }
            else{
                ans = min(ans, arr[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};
//  thsi is the optimal solution whose time complexity is reduced because of the extra for loop.

int main()
{
    vector<int> v = {4,5,6,7,0,1,2};
    // vector<int> v = {4,5,1,2,3};
    Solution s;
    int a = s.minimumValueInRotatedSortedArray(v);
    cout<< a;
    return 0;
}