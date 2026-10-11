// Nodes at Distance in Binary Tree

// Given the root of a binary tree, the value of a target node, and an integer k, return all the nodes that are exactly k edges away from the target node. Return the node values in sorted order.

// Note:

// The tree does not contain parent pointers.
// All node values are unique.
// The target node is guaranteed to be present in the tree.
// Examples:

// Input: root = [1, 2, 3, 4, 5], target = 2, k = 2   
 
// Output: [3]
// Explanation: Nodes at a distance 2 from the given node 2 is 3.


class Solution {
  public:
    Node* helper(Node* root, unordered_map<Node*, Node*> &parent_map, int target){
        queue<Node* > q;
        q.push(root);
        Node* targetNode;
        
        if(root->data == target){
            targetNode = root;
        }
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            
            if(temp->data == target){
                targetNode = temp;
            }
            
            if(temp->left){
                q.push(temp->left);
                parent_map[temp->left] = temp;
            }
            if(temp->right){
                q.push(temp->right);
                parent_map[temp->right] = temp;
            }
            
        }
        return targetNode;
    }
  
    vector<int> kDistanceNodes(Node* root, int target, int k) {
        // code here
        unordered_map<Node*, Node*> parent_map;
        
        if(root == nullptr) return {};
        
        Node* targetNode = helper(root, parent_map, target);
        
        
        unordered_map<Node*, bool> visit;
        queue<Node*> q;
        int distance = 0;
        q.push(targetNode);
        visit[targetNode] = true;
        
        while(!q.empty()){
            
            if(distance == k) break;
            int size = q.size();
            
            for(int i = 0; i< size; i++){
                
            Node* temp = q.front();
            q.pop();
            
            if(temp->left && !visit[temp->left]){
                q.push(temp->left);
                visit[temp->left] = true;
            }
            
            if(temp->right && !visit[temp->right]){
                q.push(temp->right);
                visit[temp->right] = true;
            }
            
            if(parent_map[temp] && !visit[parent_map[temp]]){
                q.push(parent_map[temp]);
                visit[parent_map[temp]] = true;
            }
            }
            distance++;
        }
        
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->data);
            q.pop();
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};