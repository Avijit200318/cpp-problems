// Top View of Binary Tree

// You a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

// Return the nodes from the leftmost node to the rightmost node.
// If multiple nodes overlap at the same horizontal position, only the topmost (closest to the root) node is included in the view. 
// Examples:

// Input: root = [1, 2, 3]
// Output: [2, 1, 3]
// Explanation: The Green colored nodes represents the top view in the below Binary tree.



class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        map<int, int> mpp;
        queue<pair<Node*, int>> q;
        vector<int> ans;
        
        if(root == nullptr) return ans;
        
        q.push({root, 0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            Node* temp = it.first;
            int line = it.second;
            
            if(mpp.find(line) == mpp.end()){
                mpp[line] = temp->data;
            }
            
            if(temp->left){
                q.push({temp->left, line-1});
            }
            
            if(temp->right){
                q.push({temp->right, line+1});
            }
        }
        
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};