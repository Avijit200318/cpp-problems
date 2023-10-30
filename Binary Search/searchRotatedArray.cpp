// this for the unique elements.
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int searchInARotatedArray(vector<int> arr, int target)
    {
        int n = arr.size();
        int low = 0, high = n-1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(arr[mid] == target)
            {
                return mid;
            }
            // left sorted
            if(arr[low] <= arr[mid])
            {
                if(arr[low] <= target && target <= arr[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            // this represent right sorted
            else{
                if(arr[mid] <= target && target <= arr[high])
                {
                    low = mid + 1;
                }
                else{
                    high = mid -1;
                }
            }
        }
        return -1;
    }
};
// the brute force solution has time complexity is o(n). which is linear seach. Since the vector is sorted so we can use binary search.
// this is the better and optimal solution for unique elements the timecomplexity is o(logn).

int main()
{
    vector<int> v = {7,8,9,1,2,5,4,6};
    Solution s;
    int a = s.searchInARotatedArray(v, 3);
    cout<< a;
    return 0;
}