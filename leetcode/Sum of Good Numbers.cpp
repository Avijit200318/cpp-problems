// Sum of Good Numbers

// Given an array of integers nums and an integer k, an element nums[i] is considered good if it is strictly greater than the elements at indices i - k and i + k (if those indices exist). If neither of these indices exists, nums[i] is still considered good.

// Return the sum of all the good elements in the array.
// Example 1:

// Input: nums = [1,3,2,1,5,4], k = 2

// Output: 12

// Explanation:

// The good numbers are nums[1] = 3, nums[4] = 5, and nums[5] = 4 because they are strictly greater than the numbers at indices i - k and i + k.

// Example 2:

// Input: nums = [2,1], k = 1

// Output: 2

// Explanation:

// The only good number is nums[0] = 2 because it is strictly greater than nums[1]

class Solution {
public:
    bool isValid(int idx,int n){
        if(idx < 0 || idx >= n) return false;
        return true;
    }

    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i< n; i++){
            if(!isValid(i - k, n)){
                if(nums[i] > nums[i+k]) sum += nums[i];
            }
            else if(!isValid(i + k, n)){
                if(nums[i-k] < nums[i]) sum += nums[i];
            }
            else {
                if(nums[i - k] < nums[i] && nums[i] > nums[i + k]) sum+= nums[i];
            }
        }
        return sum;
    }
};©leetcode
