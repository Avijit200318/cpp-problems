// Preorder to BST
// for bst inorder is sorted, so just sort the preorder and use both them to create the binary tree

class Solution {
  public:
    void helperInorder(vector<int> &inorder, map<int, int> &mpp){
        for(int i = 0; i< inorder.size(); i++){
            mpp[inorder[i]]= i;
        }
    }
    
    Node* helper(vector<int>& preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &mpp){
        if(preStart > preEnd || inStart > inEnd){
            return nullptr;
        }
        
        Node* root = new Node(preorder[preStart]);
        int inRoot = mpp[preorder[preStart]];
        int inLeft = inRoot - inStart;
        
        root->left = helper(preorder, preStart+1, preStart+inLeft, inorder, inStart, inRoot-1, mpp);
        root->right = helper(preorder, preStart+inLeft+1, preEnd, inorder, inRoot+1, inEnd, mpp);
        return root;
    }
    
    Node* preToBST(vector<int>& pre) {
        // code here
        vector<int> inorder(pre.begin(), pre.end());
        map<int, int> mpp;
        sort(inorder.begin(), inorder.end());
        
        helperInorder(inorder, mpp);
        
        Node* root = helper(pre, 0, pre.size()-1, inorder, 0, inorder.size()-1, mpp);
        return root;
    }
};