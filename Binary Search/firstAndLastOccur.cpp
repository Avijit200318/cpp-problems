#include<bits/stdc++.h>
using namespace std;

// class Solution{
//     public:
    // vector<int> firstAndLastOccurence(vector<int> arr, int target)
    // {
    //     int first = -1, last = -1;
    //     int n = arr.size();
    //     for(int i = 0; i< n; i++)
    //     {
    //         if(arr[i] == target)
    //         {
    //             if(first == -1)
    //             {
    //                 first = i;
    //             }
    //             else{
    //                 last = i;
    //             }
    //         }
    //     }
    //     return {first, last};
    // }

    // this is the broute force solution whose time complexity is o(n).
// };

// class Solution
// {
//     public:
//     int loweBound(vector<int> arr, int target)
//     {
//         int n = arr.size();
//         int low = 0, high = n-1;
//         int ans = -1;
//         while(low <= high)
//         {
//             int mid = (low+high)/2;
//             if(arr[mid] >= target)
//             {
//                 ans = mid;
//                 // this ans stroe the index value not the value.
//                 high = mid - 1;
//             }
//             else{
//                 low = mid + 1;
//             }
//         }
//     return ans;
//    }
//    int upperBound(vector<int> arr, int target)
//     {
//         int n = arr.size();
//         int low = 0, high = n-1;
//         int ans = -1;
//         while(low <= high)
//         {
//             int mid = (low+high)/2;
//             if(arr[mid] > target)
//             {
//                 ans = mid;
//                 high = mid - 1;
//             }
//             else{
//                 low = mid + 1;
//             }
//         }
//     return ans;
//    }
//     vector<int> firstAndLastOccurence(vector<int> arr, int target)
//     {
//         int n = arr.size();
//         int lb = loweBound(arr, target);
//         if(lb == n || arr[lb] != target)
//         {
//             return {-1, -1};
//         }
//         return {lb, upperBound(arr, target)-1};
//     }
// };
// this is the better solution or the optimal solution whose time complexity is o(logn)+o(logn).

// but if there is any restriction of lowebound and upperbound use then
class Solution
{
    public:
    int firstOccurence(vector<int> arr, int target)
    {
        int n = arr.size();
        int low = 0, high = n -1;
        int first = -1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(arr[mid] == target)
            {
                first = mid;
                high = mid - 1;
            }
            else if(arr[mid] < target)
            {
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return first;
    }
    int lastOccurence(vector<int> arr, int target){
        int n = arr.size();
        int low = 0, high = n -1;
        int last = -1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(arr[mid] == target)
            {
                last = mid;
                low = mid + 1;
            }
            else if(arr[mid] < target)
            {
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return last;
    }
    vector<int> firstAndLastOccurence(vector<int> arr, int target)
    {
        int first = firstOccurence(arr, target);
        if(first == -1)
        {
            return {-1, -1};
        }
        int last = lastOccurence(arr, target);
        return {first, last};
    }
};
// the time complesity of this code is o(logn) + o(logn).

int main()
{
    vector<int> v = {2,4,6,8,8,8,11,13};
    Solution s;
    vector<int> a = s.firstAndLastOccurence(v, 8);
    for(auto it : a)
    {
        cout<< it<< " ";
    }
    return 0;
}