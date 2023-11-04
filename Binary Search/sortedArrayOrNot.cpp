#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool isRotatedArraySortedOrNot(vector<int> arr)
    {
        int count = 0;
        int n = arr.size();
        for(int i = 1; i< n; i++)
        {
            if(arr[i] < arr[i-1])
            {
                count++;
            }
        }
        if(arr[0] < arr[n-1])
        {
            count++;
        }
        return count <= 1? true : false;
    }
};
// the time complexity of this code o(n).an this code work for duplicate value also

int main()
{
    // vector<int> v = {4,5,6,7,0,1,2};
    vector<int> v = {2,1,3,4};
    // false.
    // vector<int> v = {4,5,1,2,3};
    Solution s;
    bool a = s.isRotatedArraySortedOrNot(v);
    cout<< a;
    return 0;
}