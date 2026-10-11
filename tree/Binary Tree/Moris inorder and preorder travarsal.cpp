// Moris travarsal

// inorder
// case1: if root->left == null then print root value and move to right
// case2: if root->left value is there then check the right most element
// if the right most element have thread then remove it, add cur value and move right
// if there is no thread then create and move to cur -> left

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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;

        TreeNode* cur = root;
        while(cur != nullptr){
            if(cur->left == nullptr){
                inorder.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode* prev = cur->left;
                while(prev->right != nullptr && prev->right != cur){
                    prev = prev->right;
                }
                if(prev->right == nullptr){
                    prev->right = cur;
                    cur = cur->left;
                }
                else{
                    prev->right = nullptr;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
                
            }
        }
        return inorder;
    }
};


// preorder
// is just one line changes-> during the mark thread we will store the vavlue
// becasue the preorder is root, left, right

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
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;

        TreeNode* cur = root;

        while(cur != nullptr){
            if(cur->left == nullptr){
                preorder.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode* prev = cur->left;
                while(prev->right && prev->right != cur){
                    prev = prev->right;
                }

                if(prev->right == nullptr){
                    prev->right = cur;
                    // this line only changed
                    preorder.push_back(cur->val);
                    cur = cur->left;
                }
                else{
                    prev->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return preorder;
    }
};