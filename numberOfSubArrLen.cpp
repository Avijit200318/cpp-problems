// this is the better solution of max len of subarray len of k sum
#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    int masLenOfSubArrayEqulToKSum(vector<int> arr, int k)
    {
        int n = arr.size(), sum = 0;
        int maxLen = 0;
        unordered_map<int, int> mpp;
        for(int i = 0; i< n; i++)
        {
            sum += arr[i];
            if(sum == k)
            {
                maxLen = max(maxLen, i+1);
            }
            int rem = sum - k;

            if(mpp.find(sum) == mpp.end())
            {
                mpp[sum] = i;
            }
            if(mpp.find(rem) != mpp.end())
            {
                int len = i - mpp[rem];
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};


int main()
{
    vector<int> v = {1,2,3,-3,1,1,1,4,2,-3};
    int k = 3;
    Solution s;
    int a = s.masLenOfSubArrayEqulToKSum(v, k);
    cout<< a;
    return 0;
}