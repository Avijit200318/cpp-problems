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
    int diameter(n* root)
    {
        int diameter = 0;
        diameterHeight(root, diameter);
        return diameter;
    }
    int diameterHeight(n* root, int &diameter)
    {
        if(root == NULL)
        {
            return 0;
        }
        int lh = diameterHeight(root->left, diameter);
        int rh = diameterHeight(root->right, diameter);
        diameter = max(diameter, lh+rh);
        return 1+max(lh, rh);
    }
};
// the time complexity of this code is o(n) and space complexity is o(n).

int main()
{
    int rootValue;
    BinaryTree bt;
    cout << "enter the root value of the binary tree: ";
    cin >> rootValue;

    bt.root = new n(rootValue);
    bt.root->left = bt.root->right = nullptr;
    bt.create(bt.root);
    int a = bt.diameter(bt.root);
    cout<< a;
    return 0;
}