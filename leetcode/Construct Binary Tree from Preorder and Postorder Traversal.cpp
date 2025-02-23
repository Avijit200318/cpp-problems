// Construct Binary Tree from Preorder and Postorder Traversal

// Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
// Output: [1,2,3,4,5,6,7]

class Solution {
public:
    int preIdx = 0, postIdx = 0;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(preorder[preIdx]);
        preIdx++;

      // traverse using preorder but if the preorder and postorder value are same then increase both of them
        if(root->val != postorder[postIdx]){
            root->left = constructFromPrePost(preorder, postorder);
        }
        if(root-> val != postorder[postIdx]){
            root->right = constructFromPrePost(preorder, postorder);
        }

        postIdx++;
        return root;
    }
};
