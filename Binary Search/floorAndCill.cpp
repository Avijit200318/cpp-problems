#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int floorValue(vector<int> arr, int target)
    {
        int n = arr.size();
        int low = 0, high = n -1;
        int ans;
        while(low <= high) 
        {
            int mid = (low + high)/2;
            if(arr[mid] <= target)
            {
                ans = arr[mid];
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
    int ceilValut(vector<int> arr, int target)
    {
        int n = arr.size();
        int low = 0, high = n-1;
        int ans;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(arr[mid] >= target)
            {
                ans = arr[mid];
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
// the time complexity of this code is o(logn).
int main()
{
    vector<int> v = {10,20,30,40,50};
    Solution s;
    int a = s.floorValue(v, 25);
    int b = s.ceilValut(v, 25);
    cout<< a<< endl;
    cout<< b;
    return 0;
}