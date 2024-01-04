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

    void create(n *root)
    {
        int ans;
        n *ptr;
        cout << "do you want to create a left child of " << root->info << "?";
        cin >> ans;
        if (ans == 1)
        {
            ptr = new n(0);
            cout << "enter the value :";
            cin >> ptr->info;
            ptr->left = ptr->right = nullptr;
            root->left = ptr;
            create(root->left);
        }
        else
        {
            root->left = nullptr;
        }
        ans = 0;
        cout << "do you wnat to create a right child of " << root->info << "?";
        cin >> ans;
        if (ans == 1)
        {
            ptr = new n(0);
            cout << "enter the value: ";
            cin >> ptr->info;
            ptr->left = ptr->right = nullptr;
            root->right = ptr;
            create(root->right);
        }
        else
        {
            root->right = nullptr;
        }
    }

// using 2 stack
    // vector<int> postorder(n* root)
    // {
    //     vector<int> postorder;
    //     stack<n*> st1, st2;
    //     if(root == NULL)
    //     {
    //         return postorder;
    //     }
    //     st1.push(root);
    //     while(!st1.empty())
    //     {
    //         root = st1.top();
    //         st1.pop();
    //         st2.push(root);
    //         if(root->left != NULL)
    //         {
    //             st1.push(root->left);
    //         }
    //         if(root->right != NULL)
    //         {
    //             st1.push(root->right);
    //         }
    //     }
    //     while(!st2.empty())
    //     {
    //         postorder.push_back(st2.top()-> info);
    //         st2.pop();
    //     }
    //     return postorder;
    // }


// in this code the time complexity is o(2n) and space complexity is o(3n).

// using 1 stack
vector<int> postorder(n* root)
    {
        vector<int> postorder;
        stack<n*> st;
        while(root != NULL || !st.empty())
        {
            if(root != NULL)
            {
                st.push(root);
                root = root->left;
            }
            else{
                n* temp = st.top()->right;
                if(temp == NULL)
                {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->info);
                    while(!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->info);
                    }
                }
                else{
                    root = temp;
                }
            }

        }
        return postorder;
    }
// the time complexity of this code is o(2n) and space complexity is o(2n).
};



int main()
{
    int rootValue;
    BinaryTree bt;
    cout << "enter the root value of the binary tree: ";
    cin >> rootValue;

    bt.root = new n(rootValue);
    bt.root->left = bt.root->right = nullptr;
    bt.create(bt.root);

    cout<<endl<<"the postorder traversal is"<< endl;
    vector<int> a = bt.postorder(bt.root);
    for(auto it: a)
    {
        cout<< it<< " ";
    }
    return 0;
}