// Size of a Complete Binary Tree

// You are given the root of a complete binary tree. Your task is to find the count of nodes. A complete binary tree is a binary tree whose, all levels except the last one are completely filled, the last level may or may not be completely filled and Nodes in the last level are as left as possible.

// Note : Design an algorithm that runs better than O(n).

// Example:

// Input: Root of the below tree  


// Output: 7


// bruteforce approach->
// use any travarsal method and count all the nodes


// optimal approach using full tree formula
// if the left and right height is same then use 2^n - 1
// else use 1 + left height + right height

class Solution {
  public:
    int leftHight(Node* root){
        int count = 0;
        while(root){
            count++;
            root = root->left;
        }
        return count;
    }
    
    int rightHight(Node* root){
        int count = 0;
        while(root){
            count++;
            root = root->right;
        }
        return count;
    }
  
    int countNodes(Node* root) {
        // code here
        if(root == nullptr) return 0;
        
        int lh = leftHight(root);
        int rh = rightHight(root);
        
        if(lh == rh){
            return pow(2, lh) -1;
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};