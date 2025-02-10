// Path Sum II -> leetcode -> **before it solve sum paths problem (gfg)**

// Medium
// Topics
// Companies
// Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

// A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

// Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// Output: [[5,4,11,2],[5,8,4,5]]
// Explanation: There are two paths whose sum equals targetSum:

class Solution {
public:
    void solve(TreeNode* root, int target, vector<vector<int>> &ans, vector<int> &path){
        if(root == nullptr) return;

        path.push_back(root->val);

        solve(root->left, target, ans, path);
        solve(root->right, target, ans, path);

        int sum = 0;
        for(int i = 0; i< path.size(); i++){
            sum+= path[i];
        }
            if(sum == target && !root->left && !root->right){
                ans.push_back(path);
            }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        
        solve(root, targetSum, ans, path);
        return ans;
    }
};
