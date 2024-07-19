class Solution {
public:

    bool canweplace(vector<int> arr, int dis, int k)
    {
        int count = 1, last = arr[0];
        int n = arr.size();
        for(int i = 1; i< n; i++)
        {
            if(arr[i] - last >= dis)
            {
                count++;
                last = arr[i];
            }
        }
        if(count >= k)
        {
            return true;
        }
        return false;
    }
    
    int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin(), stalls.end());
        int ans = 1;
        int low = 1, high = stalls[n-1] - stalls[0];
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(canweplace(stalls, mid, k) == true)
            {
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return ans;
    }
};
