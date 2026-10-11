// Flatten Binary Tree to Linked List

// Given the root of a binary tree, flatten the tree into a Linked list:

// The linked list should use the same Node class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The linked list nodes should be in the same order as a preorder traversal of the binary tree.
// Examples:

// Input: root[] = [1, 2, 5, 3, 4, 6]

// Output: [1, 2, 3, 4, 5, 6]  
// Explanation: After flattening, the tree looks like:
//      1
//       \
//        2
//         \
//          3
//           \
//            4
//             \ 
//              5 
//               \
//                6
// Here, left of each node points to NULL and right contains the next node in preorder.The inorder traversal of this flattened tree is 1 2 3 4 5 6.


// **** RECURSIVE SOLUTION***

class Solution {
  public:
    void helper(Node* root, Node* &prev){
        if(root == nullptr) return;
        
        helper(root->right, prev);
        helper(root->left, prev);
        
        root->right = prev;
        root->left = nullptr;
        
        prev = root;
    }
    
    void flatten(Node* root) {
        // code here
        Node* prev = nullptr;
        
        helper(root, prev);
    }
};



// ****USING STACK****

class Solution {
  public:
    void flatten(Node* root) {
        // code here
        stack<Node*> st;
        
        st.push(root);
        
        while(!st.empty()){
            Node* temp = st.top();
            st.pop();
            
            if(temp->right){
                st.push(temp->right);
            }
            
            if(temp->left){
                st.push(temp->left);
            }
            
            if(!st.empty()){
                temp->right = st.top();
            }
            temp->left = nullptr;
        }
    }
};