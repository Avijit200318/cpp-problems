#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int info;
    Node *rc, *lc;

    Node(int value) : info(value), rc(nullptr), lc(nullptr) {}
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
            ptr->lc = ptr->rc = nullptr;
            root->lc = ptr;
            create(root->lc);
        }
        else
        {
            root->lc = nullptr;
        }
        ans = 0;
        cout << "do you wnat to create a right child of " << root->info << "?";
        cin >> ans;
        if (ans == 1)
        {
            ptr = new n(0);
            cout << "enter the value: ";
            cin >> ptr->info;
            ptr->lc = ptr->rc = nullptr;
            root->rc = ptr;
            create(root->rc);
        }
        else
        {
            root->rc = nullptr;
        }
    }
    void preorder(n* root)
    {
        if(root == nullptr)
        {
            return;
        }
        cout<< root->info<<" ";
        preorder(root->lc);
        preorder(root->rc);
    }
    void inorder(n* root)
    {
        if(root == nullptr)
        {
            return;
        }
        inorder(root->lc);
        cout<< root->info<< " ";
        inorder(root->rc);
    }

    void postorder(n* root)
    {
        if(root == nullptr)
        {
            return;
        }
        postorder(root->lc);
        postorder(root->rc);
        cout<< root->info<< " ";
    }
};

int main()
{
    int rootValue;
    BinaryTree bt;
    cout << "enter the root value of the binary tree: ";
    cin >> rootValue;

    bt.root = new n(rootValue);
    bt.root->lc = bt.root->rc = nullptr;
    bt.create(bt.root);
    cout<<"the preorder traversal is "<<endl;
    bt.preorder(bt.root);
    cout<<endl<<"the inorder tranversal is"<< endl;
    bt.inorder(bt.root);
    cout<<endl<<"the postorder traversal is"<< endl;
    bt.postorder(bt.root);
    return 0;
}