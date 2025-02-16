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
};

// ***********************Leetcode using string instead of array ********************


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// stringstream help to travarse it like an object since we add ',' to seperate every element. and getinline() takes three thing one is stringstream variable, string and a seperator(',').
// getinline help to traverse to next element
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp == nullptr){
                s.append("#,");
            }
            else{
                s.append(to_string(temp->val) + ',');
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();
        if(n == 0) return nullptr;

        string str;
        stringstream s(data);
        getline(s, str, ',');
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            getline(s, str, ',');
            if(str != "#"){
                temp->left = new TreeNode(stoi(str));
                q.push(temp->left);
            }
            getline(s, str, ',');

            if(str != "#"){
                temp->right = new TreeNode(stoi(str));
                q.push(temp->right);
            }
            
        }
        return root;
    }
};

