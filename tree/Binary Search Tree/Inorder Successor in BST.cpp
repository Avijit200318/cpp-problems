// Inorder Successor in BST

// Given a BST, and a reference to a Node k in the BST. Find the Inorder Successor of the given node in the BST. If there is no successor, return -1. 

// Examples :

// Input: root = [2, 1, 3], k = 2
// Output: 3 
// Explanation: Inorder traversal : 1 2 3 Hence, inorder successor of 2 is 3.

class Solution {
  public:
    bool helper(Node* root, Node* k, int &ans){
        if(root == nullptr) return false;
        
        if(helper(root->left, k, ans)) return true;
        
        if(root->data > k->data){
            ans = root->data;
            return true;
        }
        
        if(helper(root->right, k, ans)) return true;
    }
    
    int inOrderSuccessor(Node *root, Node *k) {
        // code here
        if(root == nullptr) return -1;
        int ans = -1;
        
        bool a = helper(root, k, ans);
        return ans;
    }
};

// **** optimal approach***
class Solution {
  public:
    void helper(Node* root, Node* k, int &ans){
        while(root != nullptr){
            // if the target is high or equal to root then we need to move right because we want higher value
            if(k->data >= root->data){
                root = root->right;
            }
            else{
                // if the root value became bigger than target then store it and move left. because we want just the next highest value
                ans = root->data;
                root = root->left;
            }
        }
    }
  
    int inOrderSuccessor(Node *root, Node *k) {
        // code here
        int ans = -1;
        if(root == nullptr) return ans;
        
        helper(root, k, ans);
        return ans;
    }
};