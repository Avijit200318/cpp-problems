// Kahn's algorighm     -   Topological sort(BFS)

class Solution {
  public:
    vector<int> topoSort(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> indegree(n, 0);
        
        // adding indegree values.
        for(int i = 0; i< n; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        // BFS (updated)
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
            // answer is stored for topological sort. now remove that branck from indegree
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        return ans;
    }
};