class Solution {
  public:
  int totalDay(int arr[], int n, int d, int mid)
  {
    int load = 0, day = 0;
    for(int i = 0; i< n; i++)
    {
        if(load + arr[i] > mid)
        {
            day++;
            load = arr[i];
        }
        else{
            load += arr[i];
        }
    }
    day++;
    return day;
  }
  
    int leastWeightCapacity(int arr[], int n, int d) {
        int sum = 0;
        int maxi = INT_MIN;
        for(int i = 0; i< n; i++)
        {
            sum += arr[i];
            maxi = max(maxi, arr[i]);
        }
        int low = maxi, high = sum;
        int ans= maxi;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(totalDay(arr, n, d, mid) <= d)
            {
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid +1;
            }
        }
        return ans;
        
    }
};
