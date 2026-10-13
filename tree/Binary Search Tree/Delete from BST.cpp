// Delete from BST

// Given a binary search tree and a node value x. Delete the node with the given value x from the tree. If no node with value x exists, then do not make any change. 

// Return the root of the tree after deleting the node with value x.

// Note: You may return any valid BST after deleting the specified node. The driver code will print true if the resulting tree is a valid BST after deletion, and false otherwise.

// Examples :

// Input: root = [2, 1, 3], x = 12

// Output: true
// Explanation: In the given input there is no node with value 12, so the tree will remain same.


class Solution {
  public:
    // move node's right corner
    Node* rootsRight(Node* root){
        Node* cur = root;
        while(root->right != nullptr){
            root = root->right;
        }
        return root;
    }
  
    // perform the deletion task
    Node* helper(Node* root){
        // if there is no left of the node we want to delete then return its right and vice varsa.
        if(root->left == nullptr){
            return root->right;
        }
        else if(root->right == nullptr){
            return root->left;
        }
        
        // if we have both the right and left node then first store the rightChild
        // then move to left and go to the right corner. then add the rightcorner node -> right to right child and return root->left.
        Node* rightChild = root->right;
        Node* leftsRightCorner = rootsRight(root->left);
        leftsRightCorner->right = rightChild;
        return root->left;
    }
  
    Node* delNode(Node* root, int x) {
        if(root == nullptr) return nullptr;
        
        // if the root node is the node we want to delete
        if(root->data == x){
            return helper(root);
        }
        
        Node* cur = root;
        
        while(root != nullptr){
            if(root->data > x){
                // if we have left and the left value is the node we want to delete then send it to helper. 
                // helper will return that nodes left or right child. so connect it with root->left (current)
                if(root->left && root->left->data == x){
                    root->left = helper(root->left);
                    break;
                }
                else{
                    root = root->left;
                }
            }
            else{
                if(root->right && root->right->data == x){
                    root->right = helper(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }
        }
        return cur;
    }
};