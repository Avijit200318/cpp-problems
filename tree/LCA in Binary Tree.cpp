// LCA in Binary Tree

// Given the root of a binary tree with all unique values and two nodes value, n1 and n2.

// Find the lowest common ancestor of the given two nodes. Both node values are always present in the Binary Tree.

// Note: LCA is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

// Examples:

// Input: root = [1, 2, 3, 4, 5, 6, 7], n1 = 4, n2 = 5    

// Output: 2



// solution finding the paths

class Solution {
  public:
    bool getPath(Node* root, int x, vector<Node*> &ans){
        if(root == nullptr){
            return false;
        }
        
        ans.push_back(root);
        if(root->data == x){
            return true;
        }
        
        if(getPath(root->left, x, ans)){
            return true;
        }
        
        if(getPath(root->right, x, ans)){
            return true;
        }
        
        ans.pop_back();
        return false;
    }
  
    Node* lca(Node* root, int n1, int n2) {
        //  code here
        vector<Node*> path1, path2;
        if(root == nullptr) return nullptr;
        
        getPath(root, n1, path1);
        getPath(root, n2, path2);
        
        Node* ans = root;
        
        int i = 0, j = 0;
        int n = path1.size(), m = path2.size();
        
        while(i < n && j < m){
            if(path1[i]->data == path2[j]->data){
                ans = path2[i];
            }
            else{
                break;
            }
            i++;
            j++;
        }
        
        return ans;
    }
};


// MORE OPTIMAL SOLUTION

class Solution {
  public:
    Node* lca(Node* root, int n1, int n2) {
        //  base condition if we find any of the ndoe then return node. if root is null then return null
        if(root == nullptr || n1 == root->data || n2 == root->data){
            return root;
        }
        
        Node* left = lca(root->left, n1, n2);
        Node* right = lca(root->right, n1, n2);
        
        // we will travarse left and right
        // if left is null then take right node. if right is null then take left node. if both is null or both have values then take root

        if(!left){
            return right;
        }
        else if(!right){
            return left;
        }
        else{
            return root;
        }
    }
};