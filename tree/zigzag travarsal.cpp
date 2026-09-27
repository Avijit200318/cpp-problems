// Zig-Zag Tree Traversal
// Solved
// Difficulty: MediumAccuracy: 54.05%Submissions: 441K+Points: 4Average Time: 30m
// Given the root of a binary tree. Find the zig-zag level order traversal of the binary tree.
// Note: In zig zag traversal we traverse the nodes from left to right for odd-numbered levels, and from right to left for even-numbered levels.

// Examples:

// Input: root = [1, 2, 3, 4, 5, 6, 7]
          
// Output: [1, 3, 2, 4, 5, 6, 7]
// Explanation:
// Level 1 (left to right): [1]
// Level 2 (right to left): [3, 2]
// Level 3 (left to right): [4, 5, 6, 7]
// Final result: [1, 3, 2, 4, 5, 6, 7]


class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
        vector<int> ans;
        if(root == nullptr) return ans;
        
        queue<Node* > q;
        q.push(root);
        
        bool id = true;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size);
            
            for(int i = 0; i< size; i++){
                Node* t = q.front();
                q.pop();
                
                int idx = id? i : size-1-i;
                temp[idx] = t->data;
                
                if(t->left != nullptr){
                    q.push(t->left);
                }
                
                if(t->right != nullptr){
                    q.push(t->right);
                }
            }
            id = !id;
            ans.insert(ans.end(), temp.begin(), temp.end());
        }
        return ans;
    }
};