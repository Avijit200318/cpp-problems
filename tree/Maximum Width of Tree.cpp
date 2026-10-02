// Maximum Width of Tree

// Given a Binary Tree, find the maximum width of it. Maximum width is defined as the maximum number of nodes at any level.

// Examples:

// Input: root = [1, 2, 3, 4, 5, 6, 7]
          
// Output: 4
// Explanation: On the first level there is only one node [1]. On the second level there are two nodes [2, 3]. On the third level there are 4 nodes [4, 5, 6, 7], clearly it is the maximum number of nodes at any level.

/*  Structure of a Binary Tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/



// ****if we use normal indexing then it might get overflow or out of bound***
// so we need to fix this index method
// instead of using 2 * i + 1, 2 * i + 2 first we will substract it with the minimum value.
// then we will use this value as index.

class Solution {
  public:
    int maxWidth(Node* root) {
        // code here
        if(root == nullptr) return 0;
        
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        int ans = 1;
        int first = 0, last = 0;
        
        while(!q.empty()){
            int size = q.size();
            // taking the minimum value
            int mini = q.front().second;
            
            for(int i = 0; i< size; i++){
                Node* temp = q.front().first;
                q.pop();
                int curIdx = i - mini;
                // changing the current index
                
                // saving the first and last index values
                if(i == 0){
                    first = curIdx;
                }
                if(i == size-1){
                    last = curIdx;
                }
                
                if(temp->left){
                    q.push({temp->left, (2 * curIdx) + 1});
                }
                
                if(temp->right){
                    q.push({temp->right, (2 * curIdx) + 2});
                }
            }
            // computing the width
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};