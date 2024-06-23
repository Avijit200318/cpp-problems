// count good subarray 160

class Solution {
  public:
    int maxGoodSubarrays(int n, vector<int> &arr) {
        if(n < 2)
            return 0;
        int endpoint = -1;
        int maxi = arr[0];
        for(int i = n-2; i >= 0; i--)
        {
            if(arr[i] > arr[n-1])
            {
                endpoint = i;
                break;
            }
        }
        if(endpoint == -1)
        {
            return 0;
        }
        int ans = 1;
        for(int i =1; i < endpoint; i++)
        {
            if(maxi > arr[i])
            {
                ans++;
                maxi = arr[i+1];
            }
            else{
                maxi = max(maxi, arr[i]);
            }
        }
        return ans;
    }
};
