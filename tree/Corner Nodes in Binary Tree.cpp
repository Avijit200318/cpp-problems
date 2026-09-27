// Corner Nodes in Binary Tree

// Given the root of a binary tree, find the corner elements from root to the last level. The corner elements are the leftmost and rightmost nodes at each level of the binary tree.

// Examples :

// Input: 
   
// Output: [1 2 3 4 7]
// Explanation:
// Corners at level 0: 1
// Corners at level 1: 2 3
// Corners at level 2: 4 7



class Solution {
  public:
    vector<int> getCorner(Node* root) {
        // code here
        // if we use just left view and right view combination then it might not work
        // if the tree is skew tree. then the values will added 2 times
        
        // ** we can use here level wise travarsal or printing
        
        queue<Node*> q;
        vector<int> ans;
        
        if(root == nullptr) return ans;
        
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i< size; i++){
                auto temp = q.front();
                q.pop();
                
                if(i == 0 || i == size-1){
                    ans.push_back(temp->data);
                }
                
                if(temp->left){
                    q.push(temp->left);
                }
                
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        return ans;
    }
};