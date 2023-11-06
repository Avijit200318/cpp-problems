#include<bits/stdc++.h>
using namespace std;

// class Solution
// {
//     public:
//     int findThePeakValue(vector<int> arr)
//     {
//         int n = arr.size();
//         for(int i = 0; i< n; i++)
//         {
//             if((i == 0 || arr[i] > arr[i-1]) && (i == n-1 || arr[i] > arr[i+1]))
//             {
//                 return i;
//             }
//         }
//     }
// };
// this is the bruteforce solution whose time complexity is o(n).

class Solution
{
    public:
    int findThePeakValue(vector<int> arr)
    {
        int n = arr.size();
        if(n == 1)
            return 0;
        if(arr[0] > arr[1])
            return 0;
        if(arr[n-1] > arr[n-2])
            return n-1;
        int low = 1, high = n - 2;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
            {
                return mid;
            }
            if(arr[mid] > arr[mid - 1])
            {
                low = mid + 1;
            }
            else if(arr[mid] > arr[mid + 1])
            {
                high = mid - 1;
            }
            else{
                high = mid -1;
            }
        }
        return -1;
    }
};
// this is the better solution whose time complexity is o(logn).

int main()
{
    // vector<int> v = {1,2,3,4,5,6,7,8,5,1};
    vector<int> v = {1,2,1,3,5,6,4};
    // vector<int> v = {1,5,1,2,1};
    Solution s;
    int a = s.findThePeakValue(v);
    cout<< a;
    return 0;
}