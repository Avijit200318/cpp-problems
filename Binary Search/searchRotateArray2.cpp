// here the array is contain duplicates values.
// ex [3,1,2,3,3,3,3] now in this case the previous code did not decide which portion is sorted left or right. and in this case we jsut need to return is it true or false.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchRotateArrayPosition(vector<int> arr, int target)
    {
        int n = arr.size();
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == target)
            {
                return mid;
            }
            if (arr[low] == arr[mid] && arr[mid] == arr[high])
            {
                low++;
                high--;
                continue;
            }
            // left sorted
            if (arr[low] <= arr[mid])
            {
                if (arr[low] <= target && target <= arr[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            // this represent right sorted
            else
            {
                if (arr[mid] <= target && target <= arr[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> v = {3,1,2,3,3,3,3};
    Solution s;
    int a = s.searchRotateArrayPosition(v, 3);
    cout << a;
    return 0;
}