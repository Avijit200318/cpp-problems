// Detect a Cycle in Directed Graph using BFS
// Kahn's alogright

class Solution {
  public:
    bool isCyclic(vector<vector<int>>& adj){
        int n = adj.size();
        vector<int> indegree(n, 0);
        
        for(int i = 0; i< n; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        // BFS
        queue<int> q;
        vector<int> ans;
        
        for(int i = 0; i< n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        if(ans.size() == n) return false;
        return true;
    }
};