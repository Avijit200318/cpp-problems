// Closest Nodes Queries in a Binary Search Tree

// You are given the root of a binary search tree and an array queries of size n consisting of positive integers.

// Find a 2D array answer of size n where answer[i] = [mini, maxi]:

// mini is the largest value in the tree that is smaller than or equal to queries[i]. If a such value does not exist, add -1 instead.
// maxi is the smallest value in the tree that is greater than or equal to queries[i]. If a such value does not exist, add -1 instead.
// Return the array answer.

 

// Example 1:


// Input: root = [6,2,13,1,4,9,15,null,null,null,null,null,null,14], queries = [2,5,16]
// Output: [[2,2],[4,6],[15,-1]]
// Explanation: We answer the queries in the following way:
// - The largest number that is smaller or equal than 2 in the tree is 2, and the smallest number that is greater or equal than 2 is still 2. So the answer for the first query is [2,2].
// - The largest number that is smaller or equal than 5 in the tree is 4, and the smallest number that is greater or equal than 5 is 6. So the answer for the second query is [4,6].
// - The largest number that is smaller or equal than 16 in the tree is 15, and the smallest number that is greater or equal than 16 does not exist. So the answer for the third query is [15,-1].



// ****THIS SOLUTION GIVING US TLE****
// BECAUSE IF THE BST IS SKWEED THEN TO FIND ELEMENT IT WILL TAKE O(N)
// BECAUSE OF THAT THE OVERALL SOLUTION WILL BECOME O(N^2)

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
    vector<int> helper(TreeNode* root, int k){
        
        int ceilVal = -1, floorVal = -1;

        while(root != nullptr){
            if(root->val == k){
                ceilVal = root->val;
                floorVal = root->val;
                return {floorVal, ceilVal};
            }
            else if(root->val < k){
                floorVal = root->val;
                root = root->right;
            }
            else{
                ceilVal = root->val;
                root = root->left;
            }
        }
        return {floorVal, ceilVal};
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        int n = queries.size();

        for(int i = 0; i< n; i++){
            ans.push_back(helper(root, queries[i]));
        }
        return ans;
    }
};


// *** USING BINARY SEARCH + INORDER TRAVARSAL****
// *** THE INORDER ARRAY MUST BE SEND AS REFERENCE TO FUNCTIONS***

class Solution {
public:
    void helperInorder(TreeNode* root, vector<int> &inorder){
        if(root == nullptr){
            return;
        }

        helperInorder(root->left, inorder);
        inorder.push_back(root->val);
        helperInorder(root->right, inorder);
    }

    int ceilFun(vector<int> &arr, int x){
        int ans = INT_MAX;
        int low = 0, high = arr.size()-1;

        while(low <= high){
            int mid = (low + high) / 2;

            if(arr[mid] == x){
                ans = arr[mid];
                return ans;
            }
            else if(arr[mid] < x){
                low = mid + 1;
            }
            else{
                ans = min(ans, arr[mid]);
                high = mid - 1;
            }
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }

    int floorFun(vector<int> &arr, int x){
        int ans = INT_MIN;
        int low = 0, high = arr.size()-1;

        while(low <= high){
            int mid = (low + high) / 2;

            if(arr[mid] == x){
                ans = arr[mid];
                return ans;
            }
            else if(arr[mid] > x){
                high = mid - 1;
            }
            else{
                ans = max(ans, arr[mid]);
                low = mid + 1;
            }
        }
        if(ans == INT_MIN){
            return -1;
        }
        return ans;
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        vector<int> inorder;
        helperInorder(root, inorder);

        for(int i = 0; i< queries.size(); i++){
            int f = floorFun(inorder, queries[i]);
            int c = ceilFun(inorder, queries[i]);
            ans.push_back({f, c});
        }
        return ans;
    }
};