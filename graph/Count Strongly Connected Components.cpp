// Count Strongly Connected Components

// Given a directed graph with V vertices labeled from 0 to V - 1, represented by an adjacency list adj, find number of strongly connected components (SCCs) in the graph.

// A strongly connected component is a maximal set of vertices such that every vertex is reachable from every other vertex in the same component.

// Examples:

// Input: adj[][] = [[1], [2], [0, 3], [4], [3, 5], []]
// Output: 3
// Explanation: The strongly connected components are: {0, 1, 2},{3, 4} and {5}. Therefore, the total number of SCCs is 3.
 
// Input: adj[][] = [[1], [2], [0]]
// Output: 1
// Explanation: All of the nodes are connected to each other. So, there's only one SCC.


class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visit, stack<int>& st){
        visit[node] = 1;
        
        for(auto it : adj[node]){
            if(!visit[it]){
                dfs(it, adj, visit, st);
            }
        }
        
        st.push(node);
    }
    
    void dfs2(int node, vector<vector<int>>& adj, vector<int>& visit){
        visit[node] = 1;
        
        for(auto it : adj[node]){
            if(!visit[it]){
                dfs2(it, adj, visit);
            }
        }
    }
  
    int countSCC(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> visit(n, 0);
        stack<int> st;
        
        // step:1
        
        for(int i = 0; i< n; i++){
            if(!visit[i]){
                dfs(i, adj, visit, st);
            }
        }
        
        
        
        // step2: reverse the graph
        vector<vector<int>> adjT(n);
        
        for(int i = 0; i< n; i++){
            visit[i] = 0;
            // this visit we need again when we again run dfs
            for(auto it : adj[i]){
                // i -> it we will reverse it. (it -> i)
                adjT[it].push_back(i);
            }
        }
        
        // step 3: dfs traverl again
        int cnt = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!visit[node]){
                cnt++;
                dfs2(node, adjT, visit);
            }
        }
        
        return cnt;
    }
};