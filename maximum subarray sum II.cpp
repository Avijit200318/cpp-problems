// Given an array of integers, find the contiguous subarray with the maximum sum that contains only non-negative numbers. If multiple subarrays have the same sum, return the one with the smallest starting index.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Examples:

// Input: arr[] = [1, 2, 3]
// Output: [1, 2, 3]
// Explanation: In the given array, every element is non-negative, so the entire array [1, 2, 3] is the valid subarray with the maximum sum.
// Input: arr[] = [-1, 2]
// Output: 2
// Explanation: The only valid non-negative subarray is [2], so the output is [2].
// Input: arr[] = [1, 2, 5, -7, 2, 6]
// Output: [1, 2, 5]
// Explanation: The valid non-negative subarrays are [1, 2, 5] and [2, 6]. Both have the same sum of 8, but [1, 2, 5] starts earlier, so it is the preferred subarray.


class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        int n = arr.size();
        int start = -1, end;
        int idx = -1;
        int maxVal = -1, sum = 0;
        vector<int> ans;
        map<int, pair<int, int>> mpp;
        
        for(int i = 0; i< n; i++){
            if(arr[i] > 0){
            if(start == -1) start = i;
            sum += arr[i];
            }
            else if(i != 0 && arr[i] < 0){
                idx = i;
                maxVal = max(maxVal, sum);
                mpp[sum] = {start, i-1};
                
                if(i < n-1){
                    start = -1;
                }
                sum = 0;
            }
            
        }
        
        
        if(start == -1 && maxVal == 0) return {-1};
      // the above line means when all the elements are negative then maxVal become zero due to else condition and the start index remain -1 then return {-1}
        
        if(sum > maxVal){
            maxVal = max(maxVal, sum);
            mpp[sum] = {start, n-1};
        }
        
        
        auto it = mpp[maxVal];
        for(int i = it.first; i<= it.second; i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};
