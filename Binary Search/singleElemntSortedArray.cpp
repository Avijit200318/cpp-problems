#include<bits/stdc++.h>
using namespace std;

// class Solution
// {
//     public:
//     int singleElementInASortedArray(vector<int> arr)
//     {
//         int n = arr.size();
//         for(int i = 0; i< n; i++)
//         {
//             if(i == 0)
//             {
//                 if(arr[i] != arr[i+1])
//                 {
//                     return arr[i];
//                 }
//             }
//             if(i == n-1)
//             {
//                 if(arr[n-1] != arr[n-2])
//                 {
//                     return arr[n-1];
//                 }
//             }
//             else{
//                 if(arr[i] != arr[i-1] && arr[i] != arr[i+1])
//                 {
//                     return arr[i];
//                 }
//             }
//         }
//     }
// };
// this is the bruteforce solution whose time complexity is o(n).

class Solution
{
    public:
    int singleElementInASortedArray(vector<int> arr)
    {
        int n = arr.size();
        if(n == 1)
        {
            return arr[0];
        }
        if(arr[0] != arr[1])
        {
            return arr[0];
        }
        if(arr[n-1] != arr[n-2])
        {
            return arr[n-1];
        }
        int low = 1, high = n-2;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1])
            {
                return arr[mid];
            }
            // left
            if((mid % 2 == 1 && arr[mid] == arr[mid-1]) || (mid % 2 == 0 && arr[mid] == arr[mid+1]))
            {
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};
// the time complexity of the is o(logn).

int main()
{
    vector<int> v = {1,1,2,2,3,3,4,5,5,6,6};
    Solution s;
    int a = s.singleElementInASortedArray(v);
    cout<< a;
    return 0;
}