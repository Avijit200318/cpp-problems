// Bottom View of Binary Tree

// Bottom View of Binary Tree
// Solved
// You are given the root of a binary tree, and your task is to return its bottom view. The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom.

// Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level order traversal is considered.

// Examples :

// Input: root = [1, 2, 3, 4, 5, N, 6]
    
// Output: [4, 2, 5, 3, 6]

/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> ans;
        queue<pair<Node* , int>> q;
        map<int, int> mpp;
        
        if(root == nullptr) return ans;
        
        q.push({root, 0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            Node* temp = it.first;
            int line = it.second;
            
            
                mpp[line] = temp->data;
            
            
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