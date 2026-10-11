// Right View of Binary Tree

// Given the root of a binary Tree. Return the right view of the binary tree. The right view of a Binary Tree is the set of nodes visible when the tree is viewed from the right side.

// Examples :

// Input: root = [1, 2, 3, N, N, 4, 5]
//      2_2
// Output: [1, 3, 5]



class Solution {
  public:
    void helper(Node* root, int level, vector<int> &ans){
        // reverse preorder (root, right, left)
        if(root == nullptr) return;
        
        // push value at the first level occurence
        if(level == ans.size()){
            ans.push_back(root->data);
        }
        
        helper(root->right, level+1, ans);
        helper(root->left, level+1, ans);
    }
    
    vector<int> rightView(Node *root) {
        //  code here
        vector<int> ans;
        helper(root, 0, ans);
        
        return ans;
    }
};


// ****also solve problems:
// 1. find bottom left tree value
// 2. corner nodes in binary tree