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
    bool balanceBt(n* root)
    {
        return balanceHeight(root) != -1;
    }
    int balanceHeight(n* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int lh = balanceHeight(root->left);
        int rh = balanceHeight(root->right);
        if(lh == -1 || rh == -1)
            return -1;
        if(lh - rh > 1)
            return -1;
        return 1 + max(lh, rh);
    }
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
    bool a = bt.balanceBt(bt.root);
    cout<< a;
    return 0;
}