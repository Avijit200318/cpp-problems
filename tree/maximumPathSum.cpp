class Solution {
  public:
    //Function to return maximum path sum from any node in a tree.
    int height(Node* root, int &maxi)
    {
        if(root == NULL) return 0;
        int lh= max(0, height(root->left, maxi));
        int rh = max(0, height(root->right, maxi));
        maxi = max(maxi, root->data + lh + rh);
        return root->data + max(lh, rh);
    }
    
    int findMaxSum(Node* root)
    {
        int maxi = INT_MIN;
        height(root, maxi);
        return maxi;
    }
};
