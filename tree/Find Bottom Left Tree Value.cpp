// Find Bottom Left Tree Value -> leetcode

// You are given the root of a binary tree.

// Return the leftmost value in the last row of the tree.

 

// Example 1:


// Input: root = [2,1,3]
// Output: 1
// Explanation: The last row is [1,3], so the leftmost value is 1.


class Solution {
public:
    void helper(TreeNode* root, int level, vector<int> &ans){
        if(root == nullptr) return;

        if(level == ans.size()){
            ans.push_back(root->val);
        }

        helper(root->left, level+1, ans);
        helper(root->right, level+1, ans);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        // we can store the left view then return the last value
        vector<int> ans;
        helper(root, 0, ans);

        return ans[ans.size()-1];
    }
};