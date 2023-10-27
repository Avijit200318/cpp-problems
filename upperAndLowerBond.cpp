#include<bits/stdc++.h>
using namespace std;

// class Solution{
//     public: 
//     int lowerBand(vector<int> arr, int target)
//     {
//         int n = arr.size();
//         int ans = n;
//         int low = 0, high = n - 1;
//         while(low <= high)
//         {
//             int mid = (low + high)/2;
//             if(arr[mid] >= target)
//             {
//                 ans = mid;
//                 high = mid -1;
//             }
//             else
//             {
//                 low = mid + 1;
//             }
//         }
//         return ans;
//     }
// };

class Solution{
    public: 
    int upperBand(vector<int> arr, int target)
    {
        int n = arr.size();
        int ans = n;
        int low = 0, high = n - 1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(arr[mid] > target)
            {
                ans = mid;
                high = mid -1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    // vector<int> v = {3, 5, 8, 15, 19};
    vector<int> v = {2,3,6,7,8,8,11,11,12};
    Solution s;
    // int a = s.lowerBand(v, 20);
    // int a = s.lowerBand(v, 8);
    int a = s.upperBand(v, 6);
    cout<< a;
    return 0;
}
// the time complexity of this code is o(logn).
// in c++ we can use stl for lowerband and upperband. int b = upper_bound(v.begin(), v.end(), 6);

