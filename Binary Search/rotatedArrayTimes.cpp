#include<bits/stdc++.h>
using namespace std;

// the bruteforce solution is we can check for the smallest value and its index give us the times of it rotation. tc -> o(n).
class Solution
{
    public:
    int numberOfTimesArrayIsRotated(vector<int> arr)
    {
        int n = arr.size();
        int low = 0, high = n-1;
        int idx = -1, ans = INT_MAX;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(arr[low] <= arr[high])
            {
                if(arr[low] < ans)
                {
                    ans = arr[low];
                    idx = low;
                }
                break;
            }
            if(arr[low] <= arr[mid])
            {
                if(arr[low] < ans)
                {
                    ans = arr[low];
                    idx = low;
                }
                low = mid + 1;
            }
            else{
                if(arr[mid] < ans)
                {
                    ans = arr[mid];
                    idx = mid;
                }
                high = mid - 1;
            }
        }
        return idx;
    }
};

int main()
{
    // vector<int> v = {4,5,6,7,0,1,2};
    vector<int> v = {4,5,1,2,3};
    Solution s;
    int a = s.numberOfTimesArrayIsRotated(v);
    cout<< a;
    return 0;
}