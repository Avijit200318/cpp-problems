// Check for BST -> leetcode or gfg


class Solution {
  public:
    // solve here check if each node's follow a certain range of value
    bool solve(Node* root, int minVal, int maxVal){
        if(root == nullptr) return true;
        if(root->data >= maxVal || root->data <= minVal) return false;
        
        return solve(root->left, minVal, root->data) && solve(root->right, root->data, maxVal);
    }
    
    bool isBST(Node* root) {
        return solve(root, INT_MIN, INT_MAX);
    }
    
};
