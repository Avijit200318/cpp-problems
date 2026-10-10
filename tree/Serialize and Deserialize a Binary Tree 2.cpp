// Serialize and Deserialize a Binary Tree 2

// Given the root of a binary tree. You have to perform Serialization and Deserialization. Serialization is to store a tree in an array so that it can be later restored and deserialization is reading tree back from the array. Complete the functions:

// serialize() : stores the tree into an array and returns the array.
// deSerialize() : deserializes the array to the tree and returns the root of the tree.
// Note: Multiple nodes can have the same data and the node values are always positive integers. Your code will be correct if the tree returned by deSerialize(serialize(input_tree)) is same as the input tree. Driver code will print the level order traversal of the tree returned by deSerialize(serialize(input_tree)).


class Solution {
  public:
    vector<int> serialize(Node *root) {
        //  code here
        vector<int> ans;
        if(root == nullptr) return ans;
        
        queue<Node* > q;
        q.push(root);
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            
            if(temp == nullptr){
                ans.push_back(-1);
                continue;
                // if its null value then push -1 and continue. because null don't have left and right pointer
            }
            else{
                ans.push_back(temp->data);
            }
            
            
            // we want to push null value also. so we are not using if condition that we generaly does.
            q.push(temp->left);
            q.push(temp->right);
            
        }
        return ans;
        
        
    }

    Node *deSerialize(vector<int> &arr) {
        if(arr.size() == 0){
            return nullptr;
        }
        
        queue<Node*> q;
        int idx = 0;
        
        Node* root = new Node(arr[idx]);
        idx++;
        q.push(root);
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            
            if(arr[idx] == -1){
                temp->left = nullptr;
            }
            else{
                Node* leftChild = new Node(arr[idx]);
                temp->left = leftChild;
                q.push(leftChild);
            }
            idx++;
            
            
            if(arr[idx] == -1){
                temp->right = nullptr;
            }
            else{
                Node* rightChild = new Node(arr[idx]);
                temp->right = rightChild;
                q.push(rightChild);
            }
            idx++;
        }
        
        return root;
    }
};