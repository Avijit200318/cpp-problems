class Solution {
  public:
  bool helper(vector<int> arr, int m, int k, int mid)
  {
    int count = 0, total = 0;
    int n = arr.size();
    
    for(int i = 0; i< n; i++)
    {
        if(arr[i] <= mid)
        {
            count++;
        }
        else{
            total += (count / k);
            count = 0;
        }
    }
    total += (count /k);
    if(total >= m)
    {
        return true;
    }
    return false;
  }
  
    int solve(int M, int K, vector<int> &bloomDay){
      int mini = INT_MAX, maxi = INT_MIN;
      int n = bloomDay.size();
      
      long long r = (long long)M *K;
        if(n < r)
            return -1;
      
      for(int i = 0; i< n; i++)
      {
          mini = min(mini, bloomDay[i]);
          maxi = max(maxi, bloomDay[i]);
      }
      
      int low = mini, high = maxi;
      int ans = maxi;
      while(low <= high)
      {
          int mid = (low + high)/2;
          if(helper(bloomDay, M, K, mid) == true)
          {
              ans = mid;
              high = mid - 1;
          }
          else{
              low = mid + 1;
          }
      }

      return ans;
    }
};
