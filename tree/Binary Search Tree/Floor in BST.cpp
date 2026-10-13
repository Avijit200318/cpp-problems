// Floor in BST

// Given the root of a binary search tree and a number k, find the greatest number in the binary search tree that is less than or equal to k.

// Note: If no such node value exists that is smaller than k, then return -1.

// Examples:

// Input: root = [10, 7, 15, 2, 8, 11, 16],  k  =  14

// Output: 11
// Explanation: The greatest element in the tree which is less than or equal to 14, is 11.

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        // code here
        int floorVal = -1;
        
        while(root != nullptr){
            if(root->data == k){
                floorVal = root->data;
                return floorVal;
            }
            else if(root->data < k){
                // if the root value is small then k then save it and move right to get maximum value.
                floorVal = root->data;
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
        return floorVal;
    }
};