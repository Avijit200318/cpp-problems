// DFS of Graph

// Given a connected undirected graph containing V vertices represented by a 2-d adjacency list adj[][], where each adj[i] represents the list of vertices connected to vertex i. Perform a Depth First Search (DFS) traversal starting from vertex 0, visiting vertices from left to right as per the given adjacency list, and return a list containing the DFS traversal of the graph.

// Note: Do traverse in the same order as they are in the given adjacency list.

// Examples:

// Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]

// Output: [0, 2, 4, 3, 1]
// Explanation: Starting from 0, the DFS traversal proceeds as follows:
// Visit 0 → Output: 0 
// Visit 2 (the first neighbor of 0) → Output: 0, 2 
// Visit 4 (the first neighbor of 2) → Output: 0, 2, 4 
// Backtrack to 2, then backtrack to 0, and visit 3 → Output: 0, 2, 4, 3 
// Finally, backtrack to 0 and visit 1 → Final Output: 0, 2, 4, 3, 1


class Solution {
  public:
    void helper(int val, vector<vector<int>>& adj, vector<int> &visit, vector<int> &ans){
        ans.push_back(val);
        visit[val] = 1;
        
        // save the current value and using the adj metrix move all the adjucent nodes
        for(auto it : adj[val]){
            if(!visit[it]){
                helper(it, adj, visit, ans);
            }
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> visit(n+1, 0);
        vector<int> ans;
        
        helper(0, adj, visit, ans);
        return ans;
    }
};