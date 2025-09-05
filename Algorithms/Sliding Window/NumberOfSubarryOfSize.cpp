// 2. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold -> leetcode

// Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
// Output: 3
// Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. All other sub-arrays of size 3 have averages less than 4 (the threshold).
// Example 2:

// Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
// Output: 6
// Explanation: The first 6 sub-arrays of size 3 have averages greater than 5. Note that averages are not integers.

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0, sum = 0;
        int n = arr.size(), start = 0;
        // map<int, int> mpp;  

        for(int i = 0; i< n; i++){
            // mpp[arr[i]]++;
            sum += arr[i];

            if(i - start + 1 > k){
                sum -= arr[start];
                // mpp.erase(arr[start]);
                start++;
            }

            // we are checking if the index size either reaches equal or greater to k? if so then find the average
            if(i+1 >= k && sum / k >= threshold){
                count++;
            }
        }
        return count;
    }
};