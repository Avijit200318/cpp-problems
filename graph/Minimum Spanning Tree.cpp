// // Minimum Spanning Tree / Prim's Algorithm
// Given a weighted, undirected, and connected graph represented by an adjacency list adj[][][], where adj[u] contains pairs [v, w] representing an edge from u to v with weight w.

// Find the total weight of its Minimum Spanning Tree (MST) using Prim's Algorithm.

// Input: adj[][][] = [[[1, 5], [2, 1]], [[0, 5], [2, 3]], [[0, 1], [1, 3]]]
 
// Output: 4

class Solution {
  public:
    int primMST(vector<vector<vector<int>>> &adj) {
        // we just need to find the sum
        // so we don't need to carray the paren
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = adj.size();
        vector<int> visit(n, 0);
        
        pq.push({0, 0});
        int sum = 0;
        
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            
            int node = temp.second;
            int weight = temp.first;
            
            if(visit[node] == 1) continue;
            
            // if not visited then update the visited array and add cost to sum
            visit[node] = 1;
            sum += weight;
            
            for(auto it : adj[node]){
                int adjNode = it[0];
                int w = it[1];
                
                if(!visit[adjNode]){
                    pq.push({w, adjNode});
                }
            }
        }
        return sum;
    }
};