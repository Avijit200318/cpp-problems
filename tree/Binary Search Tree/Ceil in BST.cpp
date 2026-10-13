// Ceil in BST

// Given a root binary search tree and an integer x , find the Ceil of x in the tree.

// Ceil(x) is a number that is either equal to x or is immediately greater than x. If Ceil could not be found, return -1.

// Examples:

// Input: root = [5, 1, 7, N, 2, N, N, N, 3], x = 3

// Output: 3
// Explanation: We find 3 in BST, so ceil of 3 is 3.

class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        int ceilVal = -1;
        
        while(root != nullptr){
            if(root->data == x){
                ceilVal = x;
                return ceilVal;
            }
            else if(root->data < x){
                root = root->right;
            }
            else{
                // all the values are greather store them and move left to get minimum
                ceilVal = root->data;
                root = root->left;
            }
        }
        return ceilVal;
    }
};
