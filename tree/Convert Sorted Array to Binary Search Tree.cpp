// Convert Sorted Array to Binary Search Tree
// Given an integer array nums where the elements are sorted in ascending order, convert it to a 
// height-balanced
//  binary search tree.

 

// Example 1:


// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// here the root of the tree will be the middle of the array
class Solution {
public:
    TreeNode* solve(int low, int high, vector<int> &nums){
        if(low > high) return nullptr;
        int mid = (low + high)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = solve(low, mid-1, nums);
        root->right = solve(mid + 1, high, nums);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = nullptr;
        int low = 0, high = nums.size() - 1;
        root = solve(low, high, nums);
        return root;
    }
};
