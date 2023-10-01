#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int secondLargest(vector<int> arr)
    {
        int n = arr.size();
        int large = arr[0];
        int slarge = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > large)
            {
                slarge = large;
                large = arr[i];
            }
            else if (arr[i] < large && arr[i] > slarge)
            {
                slarge = arr[i];
            }
        }
        return slarge;
    }
};

int main()
{
    vector<int> v = {1, 1, 2, 3, 3, 4, 5};
    Solution s;
    cout << s.secondLargest(v);
    return 0;
}
// the time complexity of this code is o(n);
