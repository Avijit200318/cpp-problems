// Predecessor and Successor in BST

// Given a Binary Search Tree (BST) and an integer key, find the inorder predecessor and inorder successor of the given key.

// The inorder predecessor is the node with the largest value smaller than the given key.
// The inorder successor is the node with the smallest value greater than the given key.
// If the predecessor or successor does not exist, return NULL for that position.

// Note: The key may or may not be present in the BST.

// Examples :

// Input: root = [50, 30, 70, 20, 40, 60, 80], key = 65

// Output: [60, 70]

class Solution {
  public:
    bool helperPre(Node* root, int key, Node* &pre){
        while(root != nullptr){
            if(key <= root->data){
                root = root->left;
            }
            else{
                // store value when root value is less than key. then move right becasue 
                //  we want the highest small element
                pre = root;
                root = root->right;
            }
        }
    }
    
    bool helperSus(Node* root, int key, Node* &sus){
        while(root != nullptr){
            if(key >= root->data){
                root = root->right;
            }
            else{
                sus = root;
                root = root->left;
            }
        }
    }
  
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        if(root == nullptr) return {nullptr, nullptr};
        
        Node* pre = nullptr, *sus = nullptr;
        bool a = helperPre(root, key, pre);
        bool b = helperSus(root, key, sus);
        return {pre, sus};
    }
};