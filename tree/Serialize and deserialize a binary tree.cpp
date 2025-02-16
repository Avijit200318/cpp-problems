// Serialize and deserialize a binary tree -> ***********GFG****************

// Serialization is to store a tree in an array so that it can be later restored and deserialization is reading tree back from the array. Complete the functions

// serialize() : stores the tree into an array a and returns the array.
// deSerialize() : deserializes the array to the tree and returns the root of the tree.
// Note: Multiple nodes can have the same data and the node values are always positive integers. Your code will be correct if the tree returned by deSerialize(serialize(input_tree)) is same as the input tree. Driver code will print the in-order traversal of the tree returned by deSerialize(serialize(input_tree)).

class Solution {
  public:
    // Function to serialize a tree and return a list containing nodes of tree.
    
    vector<int> serialize(Node *root) {
        vector<int> ans;
        if(root == nullptr) return ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            
            if(temp == nullptr) ans.push_back(-1);
            else{
                ans.push_back(temp->data);
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return ans;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &arr) {
        int n = arr.size();
        if(n == 0) return nullptr;
        
        queue<Node*> q;
        Node* root = new Node(arr[0]);
        q.push(root);
        int i = 1;
        while(!q.empty() && i < n){
            Node* temp = q.front();
            q.pop();
            
            if(arr[i] != -1){
                temp->left = new Node(arr[i]);
                q.push(temp->left);
            }
            i++;
            
            if(i < n && arr[i] != -1){
                temp->right = new Node(arr[i]);
                q.push(temp->right);
            }
            i++;
        }
        return root;
    }


// ***********************Leetcode using string instead of array ********************


};
