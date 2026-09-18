// Subarray Product Less Than K
// You are given an array of integers nums and an integer k.

// Return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

 

// Example 1:

// Input: nums = [10,5,2,6], k = 100
// Output: 8
// Explanation: The 8 subarrays that have product less than 100 are:
// [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
// Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
// Example 2:

// Input: nums = [1,2,3], k = 0
// Output: 0
 

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int product = 1;
        int cnt = 0;
        int n = nums.size();

        // condition to check if all the elements values are greater than vlaue of k
        bool flag = true;
        for(auto it : nums){
            if(it < k){
                flag = false;
            }
        }
        if(flag) return 0;
        // if there is no vlaue which is less than k then return 0

        for(int right = 0; right < n; right++){
            product *= nums[right];
            
            // remove element from first till the value became less than k
            while(product >= k){
                product = product / nums[left];
                left++;
            }

            // count the sub arrays [1, 2] total subarray = 3
            // [1] - > cnt = 1     [1, 2] -> cnt += 2 = 1 + 2 = 3
            cnt += right - left + 1;
        }
        return cnt;
    }
};