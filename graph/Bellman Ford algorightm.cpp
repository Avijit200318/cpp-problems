// Bellman Ford algo

// Given a weighted graph with V vertices numbered from 0 to V-1 and edges, represented by a 2d array edges[][], where edges[i] = [u, v, w] represents a direct edge from node u to v having w edge weight. You are also given a source vertex src.

// Compute the shortest distances from the src to all other vertices. If a vertex is unreachable from the src, its distance should be marked as 108. Additionally, if the graph contains a negative weight cycle, return [-1] to indicate that shortest paths cannot be reliably computed.

// Examples:


class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dis(V, 1e8);
        // given max distance will be marked 10^8
        dis[src] = 0;
        
        // we have to iterate n-1 times
        for(int i = 0; i< V-1; i++){
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int w = it[2];
                
                if(dis[u] != 1e8 && dis[u] + w < dis[v]){
                    dis[v] = dis[u] + w;
                }
            }
        }
        
        // nth iteration to check -ve cicle
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            
            if(dis[u] != 1e8 && dis[u] + w < dis[v]){
                return {-1};
            }
        }
        
        return dis;
    }
};
