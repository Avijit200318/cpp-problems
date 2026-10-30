//  Find Eventual Safe States - BFS - Topological Sort

class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // BFS / Kahn's algorightm or Topological sort
        
        vector<vector<int>> adj(V);
        
        for(int i = 0; i< edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            // u -> v I need to reverse the order first v-> u
            adj[v].push_back(u);
        }
        
        
        vector<int> indegree(V, 0);
        for(int i = 0; i< V; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        vector<int> ans;
        
        for(int i = 0; i< V; i++){
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
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};