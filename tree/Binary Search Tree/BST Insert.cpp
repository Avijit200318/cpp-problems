// BST Insert

// Given a root of Binary Search Tree (BST) and an integer key, insert a new node with value key into the BST. Return the root of the modified tree after the insertion.

// Note: If the key is already present in the BST, return the root.

class Solution {
  public:
    Node* insert(Node* root, int key) {
        if(root == nullptr){
            return new Node(key);
        }
        
        Node* cur = root;
        
        while(true){
            if(key == cur->data) return root;
            
            
            if(key > cur->data){
                if(cur->right){
                    cur = cur->right;
                }
                else{
                    cur->right = new Node(key);
                    break;
                }
            }
            else{
                if(cur->left){
                    cur = cur->left;
                }
                else{
                    cur->left = new Node(key);
                    break;
                }
            }
        }
        return root;
    }
};