// Symmetric Tree
// Solved
// Difficulty: EasyAccuracy: 44.96%Submissions: 185K+Points: 2Average Time: 20m
// Given  a root of binary tree, check whether it is symmetric, i.e., whether the tree is a mirror image of itself.


// Note: A binary tree is symmetric if the left subtree is a mirror reflection of the right subtree.

// Examples:

// Input: root = [10, 5, 5, 2, N, N, 2] 
   
// Output: true
// Explanation: As the left and right half of the above tree is mirror image, the tree is symmetric.



class Solution {
  public:
    bool helper(Node* leftNode, Node* rightNode){
        if(leftNode == nullptr || rightNode == nullptr){
            return leftNode == rightNode;
        }
        
        if(leftNode->data != rightNode->data) return false;
        
        return helper(leftNode->left, rightNode->right) && helper(leftNode->right, rightNode->left);
    }
  
    bool isSymmetric(Node* root) {
        // code here
        if(root == nullptr) return true;
        
        return helper(root->left, root->right);
    }
};