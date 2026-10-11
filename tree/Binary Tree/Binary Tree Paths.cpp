// Given the root of a binary tree, return all root-to-leaf paths in any order.

// A leaf is a node with no children.


class Solution {
public:
    void solve(TreeNode* root, string s, vector<string> &res){
        if(root == nullptr) return;
        s.append(to_string(root->val));
        if(root->left != nullptr || root->right != nullptr) s.append("->");
        if(root->left == nullptr && root->right == nullptr) res.push_back(s);

        solve(root->left, s, res);
        solve(root->right, s, res);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        solve(root, "", res);
        return res;
    }
};
