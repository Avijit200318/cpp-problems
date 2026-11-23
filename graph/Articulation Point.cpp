// Articulation Point

// Given an undirected graph with V vertices.The graph is represented as a 2D array edges[][], where each element edges[i] = [u, v] indicates an undirected edge between vertices u and v. Return all the articulation points (or cut vertices) in the graph. An articulation point is a vertex whose removal, along with all its connected edges, increases the number of connected components in the graph. 

// The given graph may be disconnected, i.e., it may consist of more than one connected component. 
// If no such point exists, return {-1}.
// Examples :

// Input: V = 5, edges[][] = [[0, 1], [1, 4], [4, 3], [4, 2], [2, 3]]

// Output: [1, 4]
// Explanation: Removing the vertex 1 or 4 will disconnects the graph as-
   
// Input: V = 4, edges[][] = [[0, 1], [0, 2]]
// Output: [0]
// Explanation: Removing the vertex 0 will increase the number of disconnected components to 3.  


class Solution {
    private:
        int timer = 1;
  public:
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& visit, vector<int>& time, vector<int>& low, vector<int>& mark){
        visit[node] = 1;
        time[node] = timer;
        low[node] = timer;
        
        timer++;
        int childCnt = 0;
        
        for(auto it : adj[node]){
            if(it == parent) continue;
            
            if(!visit[it]){
                dfs(it, node, adj, visit, time, low, mark);
                // when dfs is completed its adj node so 
                low[node] = min(low[node], low[it]);
                
                // after low updation check is it articulation point. also add parent condition
                if(low[it] >= time[node] && parent != -1){
                    mark[node] = 1;
                }
                
                // increase child count.
                childCnt++;
            }
            else{
                // min of low and time
                low[node] = min(low[node], time[it]);
            }
        }
        
        // if the child count is greater than 1 and this is parent then
        if(childCnt > 1 && parent == -1){
            mark[node] = 1;
        }
    }
        
    
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> visit(V, 0);
        vector<int> time(V), low(V);
        vector<int> ans, mark(V, 0);
        // mark will store all the node those are articulation point
        
        // perform dfs
        for(int i = 0; i< V; i++){
            if(!visit[i]){
                dfs(i, -1, adj, visit, time, low, mark);
            }
        }
        
        
        for(int i = 0; i< V; i++){
            if(mark[i] == 1){
                ans.push_back(i);
            }
        }
        
        if(ans.size() == 0){
            return {-1};
        }
        
        return ans;
    }
};