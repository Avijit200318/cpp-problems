// // Children Sum in a Binary Tree2
// Given a binary tree, find if it satisfies the Children Sum Property which has the following rules

// Each non-leaf node must have a value equal to the sum of its left and right children's values.
// A NULL child is considered to have a value of 0, and all leaf nodes are considered valid by default.

// Input: root = [35, 20, 15, 15, 5, 10, 5]

// Output: True
// Explanation: Here, every node is sum of its left and right child



class Solution {
  public:
    bool isSumProperty(Node *root) {
        // code here
        if(root == nullptr) return true;
        
        int child = 0;
        
        if(root->left){
            child += root->left->data;
        }
        
        if(root->right){
            child += root->right->data;
        }
        
        // if left and right node value different from root node and it not leaf node
        // then return false
        if(child != root->data && (root->left || root->right)){
            return false;
        }
        
        if(!isSumProperty(root->left)){
            return false;
        }
        
        if(!isSumProperty(root->right)){
            return false;
        }
        
        return true;
    }
};