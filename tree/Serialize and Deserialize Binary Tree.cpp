// Serialize and Deserialize Binary Tree

// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

// Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 
// Input: root = [1,2,3,null,null,4,5]
// Output: [1,2,3,null,null,4,5]



class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if(root == nullptr) return s;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp == nullptr){
                s.append("#,");
                continue;
            }
            else{
                s.append(to_string(temp->val) + ',');
            }

            q.push(temp->left);
            q.push(temp->right);
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return nullptr;

        queue<TreeNode*> q;

        stringstream ss(data);
        string s;
        getline(ss, s, ',');

        TreeNode* root = new TreeNode(stoi(s));
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            getline(ss, s, ',');
            if(s == "#"){
                temp->left = nullptr;
            }
            else{
                TreeNode* leftChild = new TreeNode(stoi(s));
                temp->left = leftChild;
                q.push(leftChild);
            }

            getline(ss, s, ',');
            if(s == "#"){
                temp->right = nullptr;
            }
            else{
                TreeNode* rightChild = new TreeNode(stoi(s));
                temp->right = rightChild;
                q.push(rightChild);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));