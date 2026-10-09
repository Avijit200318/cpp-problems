// Burning Tree

// Given the root of a binary tree and a target node, find the minimum time required to burn the entire tree if the target node is set on fire. In one second, the fire spreads from a node to its left child, right child, and parent.

// Note: The tree contains unique values.

// Examples : 

// Input: root = [1, 2, 3, 4, 5, 6, 7], target = 2
  
// Output: 3
// Explanation: Initially 2 is set to fire at 0 sec 
// At 1 sec: Nodes 4, 5, 1 catches fire.
// At 2 sec: Node 3 catches fire.
// At 3 sec: Nodes 6, 7 catches fire.
// It takes 3s to burn the complete tree.

/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    Node* helper(Node* root, unordered_map<Node*, Node*> &parent_map, int target){
        queue<Node*> q;
        Node* targetNode = nullptr;
        
        if(root->data == target){
            targetNode = root;
        }
        
        q.push(root);
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            if(temp->data == target){
                targetNode = temp;
            }
            
            if(temp->left){
                parent_map[temp->left] = temp;
                q.push(temp->left);
            }
            
            if(temp->right){
                parent_map[temp->right] = temp;
                q.push(temp->right);
            }
        }
        return targetNode;
    }
    
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*, Node*> parent_map;
        if(root == nullptr) return 0;
        
        Node* targetNode = helper(root, parent_map, target);
        
        if(targetNode == nullptr) return 0;
        
        unordered_map<Node*, bool> visit;
        queue<Node*> q;
        
        q.push(targetNode);
        visit[targetNode] = true;
        
        int burn = 0;
        
        while(!q.empty()){
            int size = q.size();
            bool flag = false;
            
            
            for(int i = 0; i< size; i++){
                Node* temp = q.front();
                q.pop();
                
                if(temp->left && !visit[temp->left]){
                    flag = true;
                    q.push(temp->left);
                    visit[temp->left] = true;
                }
                
                if(temp->right && !visit[temp->right]){
                    flag = true;
                    q.push(temp->right);
                    visit[temp->right] = true;
                }
                
                if(parent_map[temp] && !visit[parent_map[temp]]){
                    flag = true;
                    q.push(parent_map[temp]);
                    visit[parent_map[temp]] = true;
                }
            }
            if(flag){
                burn++;
            }
        }
        return burn;
    }
};