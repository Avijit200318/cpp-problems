// Dijkstra Algorithm

// Given a connected, weighted, undirected graph with V vertices and no negative edge weights, represented by an adjacency list adj[][][], and a source vertex src, calculate the shortest distance from src to every vertex in the graph.

// Each adj[u] contains pairs [v, wt], where v is an adjacent vertex and wt is the weight of the edge connecting vertices u and v.

// Return an array of integers where the ith element represents the shortest distance from the source vertex src to vertex i.

// Note: It is guaranteed that all the shortest distance will fit in a 32-bit integer.

// Examples:

// Input: adj[][][] = [[[1, 1], [2, 6]], [[0, 1], [2, 3]], [[0, 6], [1, 3]]], src = 2
// Output: [4, 3, 0]
// Explanation:

// Shortest Paths:
// For 2 to 0 minimum distance will be 4. By following path 2 -> 1 -> 0
// For 2 to 1 minimum distance will be 3. By following path 2 -> 1
// For 2 to 2 minimum distance will be 0. By following path 2 -> 2


class Solution {
  public:
    vector<int> dijkstra(vector<vector<vector<int>>> &adj, int src) {
        // priority_queue<Type, vector<Type>, greater<Type>> pq;
        // min priority queue
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = adj.size();
        vector<int> dis(n, INT_MAX);
        
        dis[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            // Optimization: Skip stale pairs already updated with a shorter path
            if (weight > dis[node]) continue;
            
            // if(dis[node] != INT_MAX){} WE DON'T need it here but for check we can add this
            for(auto it : adj[node]){
                int edgWeight = it[1];
                int adjNode = it[0];
                
                if(edgWeight + weight < dis[adjNode]){
                    dis[adjNode] = edgWeight + weight;
                    pq.push({dis[adjNode], adjNode});
                }
            }
        }
        return dis;
    }
};