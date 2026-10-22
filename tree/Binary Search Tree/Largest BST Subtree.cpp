// Largest BST Subtree


// Given the root of a binary tree, find the size of the largest subtree that is also a Binary Search Tree (BST). A subtree is considered a BST if, for every node in the subtree:

// All nodes in its left subtree have values less than the node's value.
// All nodes in its right subtree have values greater than the node's value.
// The subtree contains no duplicate values.
// Return the number of nodes in the largest BST subtree.

// Note: The size of a subtree is the total number of nodes it contains.



class NodeVal {
    public:
    int minVal, maxVal, maxSize;
    
    NodeVal(int minVal, int maxVal, int maxSize){
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->maxSize = maxSize;
    }
};

class Solution {
  public:
    NodeVal helper(Node* root){
        if(root == nullptr){
            return NodeVal(INT_MAX, INT_MIN, 0);
        }
        
        NodeVal left = helper(root->left);
        NodeVal right = helper(root->right);
        
        if(left.maxVal < root->data && root->data < right.minVal){
            return NodeVal(min(left.minVal, root->data), max(right.maxVal, root->data), 1 + left.maxSize + right.maxSize);
        }
        
        return NodeVal(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
        
    }
  
    int largestBst(Node *root) {
        return helper(root).maxSize;
    }
};