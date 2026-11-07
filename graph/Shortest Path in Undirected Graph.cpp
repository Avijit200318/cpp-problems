// // Shortest Path in Undirected Graph

// Given a weighted undirected graph with V vertices numbered from 1 to V and edges represented by 2D array edges[][], where edges[i] = [u, v, w] denotes an undirected edge between vertices u and v with weight w. We are also given two vertices src and dest, find the shortest path from src to dest.

// If multiple shortest paths exist with the same total weight, return the one whose sequence of vertices is lexicographically smallest.
// If no path exists between src and dest, return {-1}.
// Note: The graph contains no negative-weight edges.

// Examples :

// Input: V = 5, edges[][] = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]], src = 1, dest = 5
// Output: [1, 4, 3, 5]
// Explanation: The shortest path from vertex 1 to vertex 5 is 1 -> 4 -> 3 -> 5 with a total weight of 5.


class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        vector<vector<pair<int, int>>> adj(V+1);
        
        for(int i = 0; i< edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(V+1, INT_MAX), parent(V+1);
        
        for(int i = 0; i< V+1; i++){
            parent[i] = i;
        }
        
        pq.push({0, src});
        dis[src] = 0;
        
        while(!pq.empty()){
            auto temp = pq.top();
            int node = temp.second;
            int weight = temp.first;
            pq.pop();
            
            // optimization
            if(weight > dis[node]) continue;
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int w = it.second;
                
                if(w + weight < dis[adjNode] && weight != INT_MAX){
                    dis[adjNode] = w + weight;
                    pq.push({w + weight, adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        
        // check if it possible to reach last element
        if(dis[dest] == INT_MAX){
            return {-1};
        }
        
        int node = dest;
        vector<int> ans;
        
        while(parent[node] != node){
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(src);
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};