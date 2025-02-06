
// Code
// Testcase
// Testcase
// Test Result
// 1726. Tuple with Same Product
// Solved
// Medium
// Topics
// Companies
// Hint
// Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.

 

// Example 1:

// Input: nums = [2,3,4,6]
// Output: 8
// Explanation: There are 8 valid tuples:
// (2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
// (3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)


class Solution {
public:
    int nc2(int n){
        return n*(n-1)/2;
    }
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mpp;
        // we will strore all the tow elements product in map. then useing (a, b), (c, d) , (e, f) -> we can creeate nc2 no of tupple pairs
        for(int i = 0; i< n; i++){
            for(int j = i+1; j< n ; j++){
                mpp[nums[i] * nums[j]]++;
            }
        }

        int count = 0;
        for(auto it : mpp){
            if(it.second > 1){
                count += 8 * nc2(it.second);
            }
        }
        return count;
    }
};
