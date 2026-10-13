// Search in BST

// Given a Binary Search Tree and a node value key, return true if the node with value key is present in the BST; otherwise, return false.

// Examples:

// Input: root = [6, 2, 8, N, N, 7, 9], key = 8
    
// Output: true
// Explanation: 8 is present in the BST as right child of root.

class Solution {
  public:
    bool search(Node* root, int key) {
        // code here
        while(root != nullptr && root->data != key){
            root = root->data < key? root->right : root->left;
        }
        return root;
    }
};