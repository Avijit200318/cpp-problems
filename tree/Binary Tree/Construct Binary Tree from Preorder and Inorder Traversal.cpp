// 105. Construct Binary Tree from Preorder and Inorder Traversal
// Solved
// Medium
// Topics
// Companies
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

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
class Solution {
public:
    TreeNode* create(vector<int> preorder, int preStart, int preEnd, vector<int> inorder, int inStart, int inEnd, map<int, int> &mpp){
        if(preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = mpp[root->val];
        int numsLeft = inRoot - inStart;

        root->left = create(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1, mpp);
        root->right = create(preorder, preStart+1+numsLeft, preEnd, inorder, inRoot+1, inEnd, mpp);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mpp;
        int n = preorder.size(), m = inorder.size();
        for(int i = 0; i< m; i++){
            mpp[inorder[i]] = i;
        }

        TreeNode* root = create(preorder, 0, m-1, inorder, 0, n-1, mpp);
        return root;
    }
};
