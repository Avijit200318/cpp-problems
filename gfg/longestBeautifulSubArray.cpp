// longest beautiful sub array

class Solution {
  public:
    int longestSubarray(int n, vector<int> &arr) {
        int xorVal = 0;
        int count = 0;
        map<int, int> mpp;
        mpp[0] = -1;
        
        for(int i = 0; i< n; i++)
        {
            xorVal = xorVal ^ arr[i];
            if(mpp.find(xorVal) != mpp.end())
            {
                count = max(count, i - mpp[xorVal]);
            }
            else{
                mpp[xorVal] = i;
            }
        }
        return count;
    }
};
