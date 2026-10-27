// Directed Graph Cycle

// Given a directed graph with V vertices, numbered from 0 to V - 1, represented by an adjacency list adj[][], where adj[u] contains all vertices reachable from vertex u through a directed edge, check whether the graph contains a cycle.

// Note: The graph may have multiple connected components. Self-loops are allowed, but repeated edges are not allowed.


class Solution {
  public:
    bool helper(int start, vector<vector<int>>& adj, vector<int>& visit, vector<int>& pathVisit){
        visit[start] = 1;
        pathVisit[start] = 1;
        
        for(auto it : adj[start]){
            if(!visit[it]){
                if(helper(it, adj, visit, pathVisit) == true){
                    return true;
                }
            }
            else if(visit[it] == 1 && pathVisit[it] == 1){
                return true;
            }
        }
        
        pathVisit[start] = 0;
        return false;
    }
  
    bool isCyclic(vector<vector<int>>& adj){
        int n = adj.size();
        
        vector<int> visit(n, 0);
        vector<int> pathVisit(n, 0);
        
        // directed graph means it may happens that we need to move for a individual block
        
        for(int i = 0; i< n; i++){
            if(!visit[i]){
                if(helper(i, adj, visit, pathVisit) == true) return true;
            }
        }
        return false;
    }
};