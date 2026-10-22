// Pair Sum in BST

// Given a Binary Search Tree(BST) and a target. Check whether there's a pair of Nodes in the BST with value summing up to the target. 

// Examples:

// Input: root[] = [7, 3, 8, 2, 4, N, 9], target = 12
// bst
// Output: True
// Explanation: In the binary tree above, there are two nodes (8 and 4) that add up to 12.

class Solution {
  public:
    void helper(Node* root, vector<int> &inorder){
        if(root == nullptr) return;
        helper(root->left, inorder);
        inorder.push_back(root->data);
        helper(root->right, inorder);
    }
    
    bool twoSum(vector<int> inorder, int target){
        int low = 0;
        int high = inorder.size() - 1;
        int sum = 0;
        
        while(low < high){
            sum = inorder[low] + inorder[high];
            if(sum == target) return true;
            else if(sum > target){
                high--;
            }
            else{
                low++;
            }
        }
        return false;
    }
    
    bool findTarget(Node *root, int target) {
        vector<int> inorder;
        helper(root, inorder);
        
        return twoSum(inorder, target);
    }
};