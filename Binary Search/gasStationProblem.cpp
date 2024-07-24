// maximize max distance to the gas stations

#include<bits/stdc++.h>
using namespace std;

// class Solution{
// public:
//     long double minimiseMaxDistanceGasStation(vector<int> arr, int k)
//     {
//         int n = arr.size();
//         vector<int> hash(n-1, 0);
//         for(int i = 1; i<= k; i++)
//         {
//             long double maxVal = -1;
//             int maxId = -1;
//             for(int j = 0; j< n-1; j++)
//             {
//                 long double diff = arr[j+1] - arr[j];
//                 long double section = diff/(long double)(hash[j] + 1);
//                 if(maxVal < section){
//                     maxVal = section;
//                     maxId = j;
//                 }
//             }
//             hash[maxId]++;
//         }

//         long double ans = -1;
//         for(int i = 0; i< n-1; i++)
//         {
//             long double diff = arr[i+1] - arr[i];
//             long double section = diff/(long double)(hash[i] + 1);
//             ans = max(ans, section);
//         }
//         return ans;
//     }
// };


// this is the better solution using priority queue.
// class Solution{
// public:
//     long double minimiseMaxDistanceGasStation(vector<int> arr, int k)
//     {
//         int n = arr.size();
//         vector<int> hash(n-1, 0);
//         priority_queue<pair<long double, int>> pq;
//         for(int i = 0; i < n-1; i++)
//         {
//             pq.push({arr[i+1] - arr[i], i});
//         }

//         for(int i = 1; i<= k; i++)
//         {
//             auto tp = pq.top();
//             pq.pop();
//             int sectionIdx = tp.second;
//             hash[sectionIdx]++;
//             long double diff = arr[sectionIdx + 1] - arr[sectionIdx];
//             long double section = diff/(long double)(hash[sectionIdx] + 1);
//             pq.push({section, sectionIdx});
//         }
//         return pq.top().first;
//     }
// };

class Solution{
    public:
    int countGasStation(vector<int> arr, long double mid, int n)
    {
        int count = 0;
        for(int i = 0; i< n-1; i++)
        {
            int numbers = (arr[i+1] - arr[i])/mid;
            if((arr[i+1] - arr[i])/mid == numbers * mid)
            {
                numbers--;
            }
            count += numbers;
        }
        return count;
    }

    long double minimiseMaxDistanceGasStation(vector<int> arr, int k)
    {
        long double low = 0, high = 0;
        int n = arr.size();
        for(int i = 0; i< n-1; i++)
        {
            high = max(high, (long double)(arr[i+1] - arr[i]));
        }

        long double diff = 1e-6;
        while(high - low > diff)
        {
            long double mid = (low + high)/(2.0);
            int cnt = countGasStation(arr, mid, n);
            if(cnt > k)
            {
                low = mid;
            }
            else{
                high = mid;
            }
        }
        return high;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 6;
    // vector<int> arr = {1, 12, 17, 23};
    // int k = 5;
    Solution s;
    long double a = s.minimiseMaxDistanceGasStation(arr, k);
    cout<< a;
    return 0;
}
