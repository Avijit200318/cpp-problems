// preorder, inorder and postorder value for a binary tree using single traversal.

class Solution{
    void perInPostTraversal(Node* root)
    {
        stack<pair<Node*, int>> st;
        if(root == NULL) return NULL;
        vector<int> pre, in, post;
        st.push({root, 1});
        while(!st.empty())
        {
            auto it = st.top();
            st.pop();
            if(it.second == 1)
            {
                pre.push_back(it.first->val);
                it.second++;
                st.push(it);
                if(it.first->left != NULL)
                {
                    st.push({it.first-> left, 1});
                }
            }
            else if(it.second == 2)
            {
                in.push_back(it.first->val);
                it.second++;
                st.push(it);
                if(it.first->right != NULL)
                {
                    st.push({it.first->right, 1});
                }
            }
            else{
                post.push_back(it.first->val);
            }
        }
    }
}
