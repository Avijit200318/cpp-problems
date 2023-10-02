// given an array find the maximum lenth of concutive one.

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maximumConcucativeOnes(vector <int> arr)
    {
        int count = 0, maxi = 0;
        int n = arr.size();
        for(int i = 0; i< n; i++)
        {
            if(arr[i] == 1)
            {
                count ++;
                maxi = max(maxi, count);
            }
            else{
                count = 0;
            }
        }
        return maxi;
    }
};

// the time complexity of this code is o(n).which is an optimal solution.

int main()
{
    vector <int> v = {1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1,1};
    Solution s;
    int a = s.maximumConcucativeOnes(v);
    cout << a;
    return 0;
}