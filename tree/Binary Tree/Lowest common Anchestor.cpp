// Lowest Common Ancestor in a BST


class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        if(root == nullptr || root == n1 || root == n2) return root;
        
        Node* left = LCA(root->left, n1, n2);
        Node* right = LCA(root->right, n1, n2);

      // if the lest is null then return right and if right is null then return left but if both of them are not null then return root
        if(left == nullptr) return right;
        else if(right == nullptr) return left;
        else return root;
    }
};
