// Product of Array Except Self
// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         int mul = 1, rMul = 1;
//         vector<int> prefixMul, postifxMul(n, 0), ans;

//         for(int i = 0; i< n; i++){
//             mul *= nums[i];
//             prefixMul.push_back(mul);

//             rMul *= nums[n-i-1];
//             postifxMul[n-i-1] = rMul;
//         }

//         for(int i = 0; i< n; i++){
//             // if out of boundary of left then 1
//             int leftSideMul = i == 0? 1 : prefixMul[i-1];
//             // if out of boundary right then 1
//             int rightSideMul = i == n-1? 1 : postifxMul[i+1];

//             ans.push_back(leftSideMul * rightSideMul);
//         }
//         return ans;
//     }
// };


// this is the optimal solution here we are creating an array ans and inside it we are storing the prefix value first then postfix value to get the array. first understand the 1st solution then try this
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int prefixMul = 1, postfixMul = 1;

        // prefix default value 1 for 0 index. or when it out of boundary left side we assume it 1
        ans.push_back(1);

        for(int i = 1; i< n; i++) {
            prefixMul *= nums[i-1];
            ans.push_back(prefixMul);
        }

        // postfix default value similarly prefix
        ans[n-1] = postfixMul * ans[n-1];
        // just demo its always 1
        for(int i = n-2; i>= 0; i--){
            postfixMul *= nums[i+1];
            ans[i] = ans[i] * postfixMul;
        }

        return ans;
    }
};