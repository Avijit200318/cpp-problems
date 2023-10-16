#include<bits/stdc++.h>
using namespace std;

// class Solution{
//     public:
//     vector<int> mergeTwoSortedListWithOutExtraSpace(vector<int> arr1, vector<int> arr2)
//     {
//         int n = arr1.size();
//         int m = arr2.size();
//         vector<int> arr3(n+m);
//         int left = 0;
//         int right = 0;
//         int idx = 0;
//         while(left < n && right < m)
//         {
//             if(arr1[left] <= arr2[right])
//             {
//                 arr3[idx] = arr1[left];
//                 idx++;
//                 left++;
//             }
//             else{
//                 arr3[idx]= arr2[right];
//                 idx++;
//                 right++;
//             }
//         }
//         while(left < n)
//             arr3[idx++] = arr1[left++];
//         while(right < m)
//             arr3[idx++] = arr2[right++];
//         for(int i = 0; i< m+n; i++)
//         {
//             if(i < n)
//             {
//                 arr1[i] = arr3[i];
//             }
//             else{
//                 arr2[i-n] = arr3[i];
//             }
//         }
//         return arr1;
//     }
// };
// this is the brute force solution whose time complexity is o(n+m)+o(n+m) and space complexity is o(n+m).

// class Solution{
//     public:
//     vector<int> mergeTwoSortedListWithOutExtraSpace(vector<int> arr1, vector<int> arr2)
//     {
//         int n = arr1.size();
//         int m = arr2.size();
//         int left = n -1;
//         int right = 0;
//         while(left >= 0 && right < m)
//         {
//             if(arr1[left] > arr2[right])
//             {
//                 swap(arr1[left], arr2[right]);
//                 left--;
//                 right++;
//             }
//             else
//             {
//                 break;
//             }
//         }
//         sort(arr1.begin(), arr1.end());
//         sort(arr2.begin(), arr2.end());
//         return arr1;
//     }
// };
// this is the better solution and the time complexity is o(min(n, m))+o(nlogn)+o(nlogn) and spce complexity is o(1).

class Solution{
    private:
    void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int i, int j) {
        if (arr1[i] > arr2[j]) {
            swap(arr1[i], arr2[j]);
        }
    }
    public:
    vector<int> mergeTwoSortedListWithOutExtraSpace(vector<int>& arr1, vector<int>& arr2)
    {
        int n = arr1.size();
        int m = arr2.size();
        int len = n+m;
        int gap = (len/2) + (len%2);
        // this help us to give the selling value -> 9/2 = 4.5 = 5
        while(gap > 0)
        {
            int left = 0;
            int right = left + gap;
            while(right < len)
            {
                if(left < n && right >= n)
                {  
                    swapIfGreater(arr1, arr2, left, right - n);
                }
                else if(left >= n)
                {
                    swapIfGreater(arr2, arr2, left - n, right - n);
                }
                else{
                    swapIfGreater(arr1, arr1, left, right);
                }
                left++;
                right ++;
            }
            if(gap == 1)
                break;
            gap = (gap/2) + (gap%2);
        }
        return arr1;
    }
};
// this is the better solution whose time complexity is o(log2^(m+n))+o(n+m). and space is o(1).

int main()
{
    vector<int> v1 = {1,3,5,7};
    vector<int> v2 = {0, 2, 6, 8, 9};
    Solution s;
    vector<int> a = s.mergeTwoSortedListWithOutExtraSpace(v1, v2);
    int n = a.size();
    for(int i = 0; i< n; i++)
    {
            cout<< a[i]<< " ";
    }
    return 0;
}