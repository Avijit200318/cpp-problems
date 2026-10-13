// Lowest Common Ancestor in a BST

// Given a Binary Search Tree (BST) with unique node values and two nodes n1 and n2 (n1 != n2), find their Lowest Common Ancestor (LCA).

// The Lowest Common Ancestor (LCA) of two nodes is defined as the deepest node in the tree that has both n1 and n2 as descendants, where a node can be a descendant of itself.



// **** if both of them are left side then move there if both right then move there. but if there not both left or right side then that is the break point.
// if there one after another then also it work

class Solution {
  public:
    Node* findLCA(Node* root, Node* n1, Node* n2) {
        // code here
        if(root == nullptr) return root;
        
        int cur = root->data;
        if(cur < n1->data && cur < n2->data){
            return findLCA(root->right, n1, n2);
        }
        else if(cur > n1->data && cur > n2->data){
            return findLCA(root->left, n1, n2);
        }
        return root;
    }
};