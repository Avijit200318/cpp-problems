// Floyd Warshall

// Given a weighted directed graph, represented by an adjacency matrix dist[][], where dist[i][j] represents the weight of the edge from node i to node j. If there is no direct edge, dist[i][j] is set to a large value (i.e., 108) to represent infinity.
// The graph may contain negative edge weights, but it does not contain any negative weight cycles.

// Find the shortest distance between every pair of nodes i and j in the graph.

// Note: Modify the distances for every pair in place.

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n = dist.size();
        
        for(int i = 0; i< n; i++){
            for(int j = 0; j< n; j++){
                if(i == j){
                    dist[i][j] = 0;
                }
            }
        }
        
        for(int via = 0; via < n; via++){
            for(int i = 0; i< n; i++){
                for(int j = 0; j< n; j++){
                    // this is need because in question it says 1e8 they treated as infinite but if the weight is -ve and we sum thm then it falsely make a unrechable path rechable
                    if(dist[i][via] != 1e8 && dist[via][j] != 1e8){
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }
    }
};