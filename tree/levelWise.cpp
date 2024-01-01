#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int info;
    Node *rc, *lc;

    Node(int value) : info(value), rc(nullptr), lc(nullptr) {}
} n;

class Solution{
    public:
    n *root;

    Solution() : root(nullptr) {}

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
    vector<vector<int>> levelWisePrint(n* root)
    {
        vector<vector<int>> ans;
        if(root == nullptr)
        {
            return ans;
        }
        queue<n*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int> levelValues;
            for(int i = 0; i < size; i++)
            {
                n* temp = q.front();
                q.pop();
                levelValues.push_back(temp->info);
                if(temp->lc != NULL)
                {
                    q.push(temp->lc);
                }
                if(temp->rc != NULL)
                {
                    q.push(temp->rc);
                }
            }
            ans.push_back(levelValues);
        }
        return ans;
    }
};
// the time complexity of this code is o(n)


int main()
{
    int rootValue;
    Solution bt;
    cout << "enter the root value of the binary tree: ";
    cin >> rootValue;

    bt.root = new n(rootValue);
    bt.root->lc = bt.root->rc = nullptr;
    bt.create(bt.root);
    cout<<"level wise print is"<<endl;
    vector<vector<int>> a = bt.levelWisePrint(bt.root);
    int size = a.size();
    for(int i = 0; i< size; i++)
    {
        for(int j = 0; j < a[i].size(); j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}