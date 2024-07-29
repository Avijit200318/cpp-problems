// this is for minimum one not maximum one

class Solution {
  public:
  int lowerbound(vector<int> arr, int n, int k)
  {
    int low = 0, high = n-1;
    int ans;
    sort(arr.begin(), arr.end());
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(arr[mid] >= k){
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
  }
  
    int minRow(int n, int m, vector<vector<int>> a) {
        int countOne = 0;
        int miniOne = INT_MAX;
        int idx = -1;
        for(int i = 0; i< n; i++)
        {
            int countOne = m - lowerbound(a[i], m, 1);
            
            if(miniOne > countOne){
                miniOne = countOne;
                idx = i;
            }
        }
        return idx+1;

    }
};
