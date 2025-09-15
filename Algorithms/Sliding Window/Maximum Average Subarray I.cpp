// 4 Maximum Average Subarray I
// You are given an integer array nums consisting of n elements, and an integer k.

// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

// Example 1:

// Input: nums = [1,12,-5,-6,50,3], k = 4
// Output: 12.75000
// Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size(), start = 0;
        double sum = 0, avg = INT_MIN;

        for(int i = 0; i< n; i++){
            sum += nums[i];
            
            if(i - start + 1 > k){
                sum -= nums[start];
                start++;
            }

            if(i - start + 1 == k){
                avg = max(avg, sum / (i - start + 1));
            }
        }

        // if the the window size is equal to the array size then we just need to simply return the average
        if(k == n){
            return sum/n;
        }
        return avg;
    }
};