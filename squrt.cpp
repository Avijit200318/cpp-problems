//to get the squrt we just have to do the upperbond.
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int squrt(int n)
    {
        int low = 0;
        int high = n;
        while(low < high)
        {
            int mid = (low+high)/2;
            if(mid > n/mid)
            {
                high = mid -1;
            }
            else{
                low = mid;
            }
        }
        return low;
    }
};

int main()
{
    Solution s;
    int a = s.squrt(4);
    cout<< a;
    return 0;
}