Kth Largest in BST



class Solution {
  public:
    void helper(Node* root, int &totalNodes){
        if(root == nullptr) return;
        totalNodes++;
        helper(root->left, totalNodes);
        helper(root->right, totalNodes);
        
    }
    
    void helper2(Node* root, int &ans, int &count, int cnt){
        if(root == nullptr) return;
        helper2(root->left, ans, count, cnt);
        count++;
        if(count == cnt){
            ans = root->data;
            return;
        }
        helper2(root->right, ans, count, cnt);
    }
    
    int kthLargest(Node *root, int k) {
        int totalNodes = 0;
        helper(root, totalNodes);
        
        int cnt = totalNodes - k+1;
        int ans = -1;
        int count = 0;
        
        helper2(root, ans, count, cnt);
        return ans;
    }
};