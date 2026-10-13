// k-th Smallest in BST

// Given the root of a BST and an integer k, find the kth smallest element in the BST. If there is no kth smallest element present then return -1.

class Solution {
  public:
    void helper(Node* root, int &ans, int &cnt, int k){
        if(root == nullptr) return;
        helper(root->left, ans, cnt, k);
        cnt++;
        if(cnt == k){
            ans = root->data;
            return;
        }
        helper(root->right, ans, cnt, k);
    }
    
    int kthSmallest(Node *root, int k) {
        int ans = -1, cnt = 0;
        helper(root, ans, cnt, k);
        
        return ans;
    }
};