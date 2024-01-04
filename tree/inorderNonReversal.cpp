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

    vector<int> inorder(n* root)
    {
        vector<int> inorder;
        if(root == NULL)
        {
            return inorder;
        }
        n* temp = root;
        stack<n*> st;
        while(true)
        {
            if(temp != NULL)
            {
                st.push(temp);
                temp = temp->left;
            }
            else{
                if(st.empty())
                {
                    break;
                }
                temp = st.top();
                st.pop();
                inorder.push_back(temp->info);
                temp = temp->right;
            }
        }
        return inorder;
    }
};

int main()
{
    cout<<endl<<"the inorder tranversal is"<< endl;
    vector<int> a = bt.inorder(bt.root);
    for(auto it : a)
    {
        cout<< it << " ";
    }
    return 0;
}