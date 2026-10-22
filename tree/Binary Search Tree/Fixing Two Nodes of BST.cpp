// Fixing Two Nodes of BST

// Given the root of a Binary Search Tree (BST), where exactly two nodes have been swapped by mistake, restore the BST by swapping the values of the misplaced nodes. Return the root of the corrected BST.
 
// Note: It is guaranteed that exactly two nodes have been swapped, and restoring their values will make the tree a valid BST. The structure of the tree must remain unchanged.
 
// Examples :
// Input: root = [10, 5, 8, 2, 20]
     
// Output: [10, 5, 20, 2, 8]


// ***** we will use any travarsal and store the values. then sort the values and we will move inorder traversal.
// if the root value is different then change the root value with array value

class Solution {
  public:
    //   inorder travarsal
    void helper(Node* root, vector<int> &inorder){
        if(root == nullptr) return;
        helper(root->left, inorder);
        inorder.push_back(root->data);
        helper(root->right, inorder);
    }
    
    void traverseAndCheck(Node* root, vector<int> &inorder, int &idx){
        if(root == nullptr) return;
        traverseAndCheck(root->left, inorder, idx);
        
        // check if the root value not equal to inorder value then change it
        if(root->data != inorder[idx]){
            root->data = inorder[idx];
        }
        idx++;
        // update the index value. as for function parameter we need to sent reference of idx
        
        traverseAndCheck(root->right, inorder, idx);
    }
    
    Node* correctBST(Node* root) {
        vector<int> inorder;
        helper(root, inorder);
        
        // then sort the array. because BST inorder travarsal is sorted
        sort(inorder.begin(), inorder.end());
        
        int idx = 0;
        traverseAndCheck(root, inorder, idx);
        return root;
    }
};


// ***optimal approach***
// we will traverse inoder and store prev. if prev->data > current root->data
// then check if first == null then add values in first and mid
// else add values in last

// if first and last not null then swap them else first and mid



class Solution {
  public:
    void helper(Node* root, Node* &first, Node* &mid, Node* &last, Node* &prev){
        if(root == nullptr) return;
        
        helper(root->left, first, mid, last, prev);
        
        if(prev && root->data < prev->data){
            if(first == nullptr){
                first = prev;
                mid = root;
            }
            else{
                last = root;
            }
        }
        
        prev = root;
        
        helper(root->right, first, mid, last, prev);
    }
    
    Node* correctBST(Node* root) {
        Node* first = nullptr, *mid = nullptr, *last = nullptr, *prev = nullptr;
        helper(root, first, mid, last, prev);
        
        if(first && last){
            swap(first->data, last->data);
        }
        else if(first && mid){
            swap(first->data, mid->data);
        }
        
        return root;
    }
};