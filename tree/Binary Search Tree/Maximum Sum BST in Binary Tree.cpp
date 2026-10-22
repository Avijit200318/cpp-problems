// Maximum Sum BST in Binary Tree

// Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
 

class NodeVal{
    public:
    int minVal, maxVal, sum;

    NodeVal(int minVal, int maxVal, int sum){
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->sum = sum;
    }
};

class Solution {
public:
    NodeVal helper(TreeNode* root, int &maxSum){
        if(root == nullptr){
            return NodeVal(INT_MAX, INT_MIN, 0);
        }

        // postorder traversal
        NodeVal left = helper(root->left, maxSum);
        NodeVal right = helper(root->right, maxSum);

        if(left.maxVal < root->val && root->val < right.minVal){
            int curSum = left.sum + right.sum + root->val;
            maxSum = max(maxSum, curSum);

            return NodeVal(min(left.minVal, root->val), max(right.maxVal, root->val), curSum);
        }
        return NodeVal(INT_MIN, INT_MAX, 0);
    }

    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        helper(root, maxSum);
        return maxSum;
    }
};