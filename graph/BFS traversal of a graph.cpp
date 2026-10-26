// // BFS of Graph
// Given a connected undirected graph containing V vertices, represented by a 2-d adjacency list adj[][], where each adj[i] represents the list of vertices connected to vertex i.

// Perform a Breadth First Search (BFS) traversal starting from vertex 0, visiting vertices from left to right according to the given adjacency list, and return a list containing the BFS traversal of the graph.

// Note: Do traverse in the same order as they are in the given adjacency list.

// Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]

// Output: [0, 2, 3, 1, 4]
// Explanation: Starting from 0, the BFS traversal will follow these steps: 
// Visit 0 → Output: 0 
// Visit 2 (first neighbor of 0) → Output: 0, 2 
// Visit 3 (next neighbor of 0) → Output: 0, 2, 3 
// Visit 1 (next neighbor of 0) → Output: 0, 2, 3, 1
// Visit 4 (neighbor of 2) → Final Output: 0, 2, 3, 1, 4



class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> ans;
        int n = adj.size();
        vector<int> visit(n+1, 0);
        queue<int> q;
        
        q.push(0);
        visit[0] = 1;
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            
            ans.push_back(temp);
            
            for(auto it : adj[temp]){
                if(!visit[it]){
                    q.push(it);
                    visit[it] = 1;
                }
            }
        }
        return ans;      
    }
};

// time complexity = o(n) + o(2e) [which is for all the degrees]
// 