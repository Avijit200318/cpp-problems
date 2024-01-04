#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int info;
    Node *right, *left;

    Node(int value) : info(value), right(nullptr), left(nullptr) {}
} n;

class BinaryTree
{
public:
    n *root;

    BinaryTree() : root(nullptr) {}

    vector<int> preorderWithOutRecursion(n* root)
    {
        vector<int> preorder;
        if(root == NULL)
        {
            return preorder;
        }
        stack<n*> st;
        st.push(root);
        while(!st.empty())
        {
            n* temp = st.top();
            st.pop();
            preorder.push_back(temp->info);
            if(temp->right != NULL)
            {
                st.push(temp->right);
            }
            if(temp -> left != NULL)
            {
                st.push(temp->left);
            }
        }
        return preorder;
    }
};
// the time complexity of this code is o(n).

int main()
{
    vector<int> a = bt.preorder(bt.root);
    for(auto it : a)
    {
        cout<< it<< " ";
    }
    return 0;
}