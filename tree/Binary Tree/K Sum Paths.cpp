// K Sum Paths

// Given a binary tree and an integer k, determine the number of downward-only paths where the sum of the node values in the path equals k. A path can start and end at any node within the tree but must always move downward (from parent to child).

// Examples:

// Input: k = 7   

// Output: 3
// Explanation: The following paths sum to k 

class Solution {
  public:
  void helper (Node* root, int k, vector<int> &path, int &ans){
     if(root == nullptr) return;
     
     path.push_back(root->data);
     helper(root->left, k, path, ans);
     helper(root->right, k, path, ans);
     
     int sum = 0;
     for(int i = path.size()-1; i>= 0; i--){
         sum += path[i];
         if(sum == k) ans++;
     }
     path.pop_back();
  }
  
    int sumK(Node *root, int k) {
        int ans = 0;
        vector<int> path;
        helper(root, k, path, ans);
        return ans;
    }
};
