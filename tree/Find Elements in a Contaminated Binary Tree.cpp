// Find Elements in a Contaminated Binary Tree ->> leetcode problem

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    set<int> st;
    void helper(TreeNode* root, int val){
        if(root == nullptr) return;

        st.insert(val);
        helper(root->left, val*2 + 1);
        helper(root->right, val*2 + 2);
    }

    FindElements(TreeNode* root) {
        helper(root, 0);
    }
    
    bool find(int target) {
        return st.count(target) > 0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
