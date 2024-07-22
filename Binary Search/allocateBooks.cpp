class Solution {
  public:
    int helper(int arr[], int n, int mid)
    {
        int student = 1;
        long long preSum = 0;

        for(int i = 0 ;i< n; i++)
        {
            if( preSum + arr[i] <= mid)
            {
                preSum += arr[i];
            }
            else{
                student++;
                preSum = arr[i];
            }
        }
        return student;
    }
    
    long long findPages(int n, int arr[], int m) {
        // code here
        int maxi = INT_MIN;
        long long sum = 0;
        if(m > n){
            return -1;
        }
        
        for(int i = 0; i< n; i++)
        {
            maxi = max(maxi, arr[i]);
            sum += arr[i];
        }
        
        long long low = maxi, high = sum;
        
        long long ans = -1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(helper(arr, n, mid) > m){
                low = mid + 1;
            }
            else{
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;

    }
};
