// Binary Tree from Inorder and Postorder

// Given two arrays representing the inorder and postorder traversals of a binary tree, your task is to construct the binary tree and return its root.

// Note: The inorder and postorder traversals contain unique values, and every value present in the postorder traversal is also found in the inorder traversal.

// Examples:

// Input: inorder[] = [4, 8, 2, 5, 1, 6, 3, 7], postorder[] = [8, 4, 5, 2, 6, 7, 3, 1]
// Output: [1, 2, 3, 4, 5, 6, 7, N, 8]
// Explanation: For the given inorder and postorder traversal of tree the resultant binary tree will be:




class Solution {
  public:
    Node* helper(vector<int> inorder, int inStart, int inEnd, vector<int> postorder, int postStart, int postEnd, map<int, int> &mpp){
        if(inStart > inEnd || postStart > postEnd) return nullptr;
        
        Node* root = new Node(postorder[postEnd]);
        
        int inRoot = mpp[root->data];
        int inLeft = inRoot - inStart;
        
        root->left = helper(inorder, inStart, inRoot-1, postorder, postStart, postStart+inLeft-1, mpp);
        root->right = helper(inorder, inRoot+1, inEnd, postorder, postStart+inLeft, postEnd-1, mpp);
        return root;
        
    }
  
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // code here
        map<int, int> mpp;
        
        for(int i = 0; i< inorder.size(); i++){
            mpp[inorder[i]] = i;
        }
        
        Node* root = helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mpp);
        return root;
    }
};