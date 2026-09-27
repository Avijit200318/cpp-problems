// Vertical Order Traversal of a Binary Tree -> leetcode
// Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

// For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

// The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

// Return the vertical order traversal of the binary tree.


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> mpp;

        if(root == nullptr) return {};

        q.push({root, {0, 0}});

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            TreeNode* temp = p.first;
            int x = p.second.first;
            int y = p.second.second;

            mpp[x][y].insert(temp->val);

            if(temp->left){
                q.push({temp->left, {x-1, y+1}});
            }

            if(temp->right){
                q.push({temp->right, {x+1, y+1}});
            }
        }

        vector<vector<int>> ans;

        for(auto p : mpp){
            vector<int> temp;
            for(auto q : p.second){
                temp.insert(temp.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


// Vertical Tree Traversal -> GFG
// Given the root of a Binary Tree, find the vertical traversal of the tree starting from the leftmost level to the rightmost level.

// Note: If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

// *** for gfg we need to use vector because  but in leetcode we need to use multiset

/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        queue<pair<Node*, pair<int, int>>> q;
        map<int, map<int, vector<int>>> mpp;
        
        if(root == nullptr) return {{}};
        
        q.push({root, {0, 0}});
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            
            Node* temp = p.first;
            int x = p.second.first;
            int y = p.second.second;
            
            mpp[x][y].push_back(temp->data);
            
            if(temp->left){
                q.push({temp->left, {x-1, y+1}});
            }
            
            if(temp->right){
                q.push({temp->right, {x+1, y+1}});
            }
        }
        
        vector<vector<int>> ans;
        
        for(auto p : mpp){
            vector<int> temp;
            for(auto q : p.second){
                temp.insert(temp.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


// we also can use anyorder travarsal
// bellow one is preorder travarsal

class Solution {
  public:
    // ***  preorder travarsal ***
    void helper(Node* root, map<int, map<int, vector<int>>> &mpp, int x, int y){
        if(root == nullptr){
            return;
        }
        
        mpp[x][y].push_back(root->data);
        helper(root->left, mpp, x-1, y+1);
        helper(root->right, mpp, x+1, y+1);
    }
    
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        map<int, map<int, vector<int>>> mpp;
        helper(root, mpp, 0, 0);
        
        vector<vector<int>> ans;
        
        for(auto p : mpp){
            vector<int> temp;
            for(auto q : p.second){
                temp.insert(temp.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};