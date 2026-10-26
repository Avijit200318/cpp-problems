// Undirected Graph Cycle

// Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

// Note: The graph can have multiple component.

// Examples:

// Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
// Output: true
// Explanation: 

// 1 -> 2 -> 0 -> 1 is a cycle.


// ****using BFS Traversal****

class Solution {
  public:
    bool helper(int start, vector<vector<int>>& adj, vector<int>& visit){
        queue<pair<int, int>> q;
        // queue will store node values and parent value. For the first value we set it -1.
        q.push({start, -1});
        visit[start] = 1;

        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto it : adj[node]){
                if(!visit[it]){
                    q.push({it, node});
                    visit[it] = 1;
                }
                else if(parent != it){
                    // visited but not the parent node
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> visit(V, 0);

        for(int i = 0; i< edges.size(); i++){
            int u = edges[i][0];
            int v= edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        // if there is multiple separate graph then we need to check all of them
        for(int i = 0; i< V; i++){
            if(!visit[i]){
                if(helper(i ,adj, visit)) return true;
            }
        }
        return false;
        
    }
};


// ****using DFS Travarsal***

class Solution {
  public:
    bool helper(int start, int parent, vector<vector<int>>& adj, vector<int>& visit){
        visit[start] = 1;
        
        for(auto it : adj[start]){
            if(!visit[it]){
                if(helper(it, start, adj, visit)){
                    return true;
                    // if any moment we get a true then return true
                }
            }
            else if(visit[it] && parent != it){
                return true;
                // if we ge a visisted elemnt and that is not parent then return true
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> visit(V, 0);

        for(int i = 0; i< edges.size(); i++){
            int u = edges[i][0];
            int v= edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        for(int i = 0; i< V; i++){
            if(!visit[i]){
                if(helper(i, -1 ,adj, visit)) return true;
            }
        }
        return false;
        
    }
};