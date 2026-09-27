// Tree Boundary Traversal

// Given a root of a Binary Tree, return its boundary traversal in the following order:

// Left Boundary: Nodes from the root to the leftmost non-leaf node, preferring the left child over the right and excluding leaves.
// Leaf Nodes: All leaf nodes from left to right, covering every leaf in the tree.
// Reverse Right Boundary: Nodes from the root to the rightmost non-leaf node, preferring the right child over the left, excluding leaves, and added in reverse order.
// Note: The root is included once, leaves are added separately to avoid repetition, and the right boundary follows traversal preference not the path from the rightmost leaf.

// Examples:

// Input: root = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
// Output: [1, 2, 4, 8, 9, 6, 7, 3]



class Solution {
  public:
    bool isLeaf(Node* root){
        if(root->left == nullptr && root->right == nullptr) return true;
        return false;
    }
    
    void leftTravarsal(Node* root, vector<int> &ans){
        Node* cur = root->left;
        
        while(cur){
            if(!isLeaf(cur)){
                ans.push_back(cur->data);
            }
            
            if(cur->left){
                cur = cur->left;
            }
            else{
                cur = cur->right;
            }
        }
    }
    
    void leafTravarsal(Node* root, vector<int> &ans){
        if(root == nullptr) return;
        
        if(isLeaf(root)){
           ans.push_back(root->data);
        }
        
        leafTravarsal(root->left, ans);
        leafTravarsal(root->right, ans);
    }
    
    void rightTravarsal(Node* root, vector<int> &ans){
        Node* cur = root->right;
        stack<int> st;
        
        while(cur){
            if(!isLeaf(cur)){
                st.push(cur->data);
            }
            
            if(cur->right){
                cur = cur->right;
            }
            else{
                cur = cur->left;
            }
        }
        
        while(!st.empty()){
            int temp = st.top();
            st.pop();
            ans.push_back(temp);
        }
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(root == nullptr) return ans;
        
        if(!isLeaf(root)){
            ans.push_back(root->data);
        }
        
        leftTravarsal(root, ans);
        leafTravarsal(root, ans);
        rightTravarsal(root, ans);
        
        return ans;
    }
};