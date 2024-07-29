class Solution{   
public:
    int upperbound(vector<int> arr, int m, int k)
    {
        int low = 0, high = m-1;
        int ans = m;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(arr[mid] > k)
            {
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }

    int countHowMiniEqual(vector<vector<int>> arr, int n, int m, int mid)
    {
        int count = 0;
        for(int i = 0; i< n; i++)
        {
            count += upperbound(arr[i], m, mid);
        }
        return count;
    }

    int median(vector<vector<int>> &matrix, int R, int C){
        int mini = INT_MAX, maxi = INT_MIN;
        int m = matrix[0].size();
        int n = matrix.size();
        
        for(int i = 0; i< n; i++)
        {
            mini = min(matrix[i][0], mini);
            maxi = max(matrix[i][m-1], maxi);
        }
        
        int low = mini, high = maxi;
        int req = (n* m)/2;
        while(low <= high)
        {
            int mid = (low + high)/2;
            int count = countHowMiniEqual(matrix, n, m, mid);
            if(count <= req){
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return low;
        
        
    }
};
