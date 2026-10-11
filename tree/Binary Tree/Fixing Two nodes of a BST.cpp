// Fixing Two nodes of a BST

// Given the root of a Binary search tree(BST), where exactly two nodes were swapped by mistake. Your task is to fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
// Note: It is guaranteed that the given input will form BST, except for 2 nodes that will be wrong. All changes must be reflected in the original linked list.

// brute force solution::: ****-----------------------
// first we can use inorder or any traversal. after that we have to sort it and then agin traverse through the tree and check root value.

// *****-------------------------

class Solution {
  public:
  void inorder(Node* root, Node* &prev, Node* &first, Node* &mid, Node* &last){
    if(root == nullptr)   return;
    
    inorder(root->left, prev, first, mid, last);
    
    if(prev != nullptr && (prev-> data > root->data)){
        if(first == nullptr){
          // if during inorder traversal the two root which are wrong is positioned one after another the we will find only one node so for this case slect the prev node and the current node as first and mid
        first = prev;
        mid = root;
        }
        else{
            last = root;
        }
    }
    
    prev = root;
    inorder(root->right, prev, first, mid, last);
  }
  
    void correctBST(Node* root) {
        Node* first = nullptr, *mid = nullptr, *last = nullptr;
        Node* prev = new Node(INT_MIN);
        
        inorder(root, prev, first, mid, last);
        if(first && last) swap(first->data, last->data);
        else if(first && mid) swap(first->data, mid->data);
    }
};
