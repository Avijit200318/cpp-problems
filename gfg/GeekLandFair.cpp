// It is Geekland fair 2024, Geek and Geekina are enjoying the fair. They went to a juice shop in the fair. There are n types of juices each 
// having k units of juice. If Geekina drinks x units of juice of any type, Geek drinks the remaining units (k-x) of that type. Given the
// units of juice drank by the Geekina in the array a, find the minimum value of k such that the sum of juices (total units of juice) drank
// by Geek is strictly greater than Geekina. Also ensure that the remaining units (k-x) of any juice that Geek drinks is always
// non-negative (k-x>=0).

// n = 8
// a = {5, 7, 4, 8, 10, 9, 0, 6}


class Solution {
  public:
    long long minimumK(int n, vector<int> &a) {
        long long maxi = a[0];
        long long geekinaSum = 0;
        for(int i = 0; i< n; i++)
        {
            geekinaSum += a[i];
            maxi = max(maxi, (long long)a[i]);
        }
        if(maxi == 0)
        {
            return 1;
        }
        long long geekSum = 0;
        long long left = maxi, right = 4*maxi;
        long long ans = right;
        while(left <= right)
        {
            geekSum = 0;
            long long mid = (left + right)/2;
            for(int i = 0; i< n; i++)
            {
                geekSum += (mid - a[i]);
            }
            if(geekSum > geekinaSum){
                right = mid - 1;
                ans = min(ans, mid);
            }
            else{
                left = mid+1;
            }
            
        }
        return ans;
    }
};
