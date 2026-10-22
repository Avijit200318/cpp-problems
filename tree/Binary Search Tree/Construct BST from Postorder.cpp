// Construct BST from Postorder
// inorder is the sorted value of postorder for bst

// use both of them to create the tree

class Solution {
  public:
    void helperInorder(vector<int> &inorder, map<int, int> &mpp){
        for(int i = 0; i< inorder.size(); i++)    {
            mpp[inorder[i]] = i;
        }
    }
    
    Node* helper(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> &mpp){
        if(postStart > postEnd || inStart > inEnd){
            return nullptr;
        }
        
        Node* root = new Node(postorder[postEnd]);
        int inRoot = mpp[root->data];
        int inLeft = inRoot - inStart;
        
        root->left = helper(postorder, postStart, postStart+inLeft-1, inorder, inStart, inRoot-1, mpp);
        root->right = helper(postorder, postStart+inLeft, postEnd-1, inorder, inRoot+1, inEnd, mpp);
        return root;
    }
    
    Node* constructTree(vector<int>& post) {
        // code here
        vector<int> inorder(post.begin(), post.end());
        sort(inorder.begin(), inorder.end());
        map<int, int> mpp;
        
        helperInorder(inorder, mpp);
        
        return helper(post, 0, post.size()-1, inorder, 0, inorder.size()-1, mpp);
    }
};