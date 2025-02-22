// Recover a Tree From Preorder Traversal
// We run a preorder depth-first search (DFS) on the root of a binary tree.

// At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.

// If a node has only one child, that child is guaranteed to be the left child.

// Given the output traversal of this traversal, recover the tree and return its root.


class Solution {
public:
    int getVal(string s, int &n, int &pos){
        int val = 0;

        while(pos < n && s[pos] >= '0' && s[pos] <= '9'){
            val = val*10 + s[pos] - '0';
            pos++;
        }
        return val;
    }
    
    int getDash(string s, int &n, int &pos){
        int count= 0;
        while(pos <n && s[pos] == '-'){
            count++;
            pos++;
        }
        return count;
    }

    void buildTree(TreeNode* root, string s, int expect_Dash, int n, int &pos){
        if(pos == n) return;

        int prev = pos;
        int dash = getDash(s, n, pos);

        // go to previous position if dash not satisfy
        if(expect_Dash > dash){
            pos = prev;
            return;
        }

        TreeNode* temp = new TreeNode(getVal(s, n, pos));
        if(!root->left) root->left = temp;
        else root->right = temp;

        buildTree(temp, s, 1+expect_Dash, n, pos);
        buildTree(temp, s, 1+expect_Dash, n, pos);
        // here we write the same line twise it help us to back track the element when current dash and exptected dash is not equal.
    }

    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        int pos = 0;

        TreeNode* root = new TreeNode(getVal(traversal, n, pos));
        buildTree(root, traversal, 1, n, pos);
        buildTree(root, traversal, 1, n, pos);
        return root;
    }
};
