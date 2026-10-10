// Construct Tree from Inorder & Preorder

// Given two arrays representing the inorder and preorder traversals of a binary tree, construct the binary tree and return its root.

// Note: The inorder and preorder traversals contain unique values, and every value present in the preorder traversal is also found in the inorder traversal.  

// Examples:

// Input: inorder[] = [3, 1, 4, 0, 5, 2], preorder[] = [0, 1, 3, 4, 2, 5]
// Output: [0, 1, 2, 3, 4, 5]
// Explanation: The tree will look like




class Solution {
  public:
    Node* helper(vector<int> preorder, int preStart, int preEnd, vector<int> inorder, int inStart, int inEnd, map<int, int> &mpp){
        if(preStart > preEnd || inStart > inEnd) return nullptr;
        
        Node* root = new Node(preorder[preStart]);
        
        int inRoot = mpp[root->data];
        int inLeft = inRoot - inStart;
        
        root->left = helper(preorder, preStart+1, preStart + inLeft, inorder, inStart, inRoot-1, mpp);
        root->right = helper(preorder, preStart + inLeft + 1, preEnd, inorder, inRoot+1, inEnd, mpp);
        
        return root;
    }
  
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        map<int, int> mpp;
        
        for(int i = 0; i< inorder.size(); i++){
            mpp[inorder[i]] = i;
        }
        
        Node* root = helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mpp);
        return root;
    }
};