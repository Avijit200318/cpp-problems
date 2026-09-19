// Count Number of Nice Subarrays

// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.

 

// Example 1:

// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
// Example 2:

// Input: nums = [2,4,6], k = 1
// Output: 0
// Explanation: There are no odd numbers in the array.
// Example 3:

// Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
// Output: 16



//  we have to find subarray which contain exactly k odd numbers
// atmost(k) - atmost(k-1)
// shrink when invalid

class Solution {
public:
    int helper(vector<int> &arr, int k){
        int n = arr.size();
        int left = 0;
        int odd = 0;
        int ans = 0;

        for(int right = 0; right < n; right++){
            if(arr[right] % 2 != 0){
                odd++;
            }

            while(odd > k){
                if(arr[left] % 2 != 0){
                    odd--;
                }
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k-1);
    }
};