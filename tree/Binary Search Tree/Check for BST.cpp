// Check for BST

// Given a binary tree, check whether it is a Binary Search Tree (BST) or not. A binary tree is considered a BST if it satisfies the following properties:
// All nodes in the left subtree of a node have values less than the node's value.
// All nodes in the right subtree of a node have values greater than the node's value.
// Both the left and right subtrees are also Binary Search Trees.
// Return true if the given binary tree is a BST; otherwise, return false.

class Solution {
  public:
    bool helper(Node* root, int mini, int maxi){
        if(root == nullptr) return true;
        
        if(root->data >= maxi || root->data <= mini) return false;
        
        return helper(root->left, mini, root->data) && helper(root->right, root->data, maxi);
    }
    
    bool isBST(Node* root) {
        // this is the range and we are going to check if the root value in between this range.
        return helper(root, INT_MIN, INT_MAX);
    }
};