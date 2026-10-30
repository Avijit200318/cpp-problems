// Topological Sort

// Given a Directed Acyclic Graph (DAG) with V vertices numbered from 0 to V - 1, represented by an adjacency list adj[][], return a topological ordering of its vertices.

// A topological ordering is a linear ordering of vertices such that for every directed edge u -> v, vertex u appears before vertex v in the ordering.

// Note: Multiple valid topological orderings may exist. Any valid ordering is accepted. The output is true if the returned ordering is valid; otherwise, it is false.

class Solution {
  public:
    void dfs(int start, vector<vector<int>>& adj, vector<int>& visit, stack<int>& st){
        visit[start] = 1;
        
        for(auto it : adj[start]){
            if(!visit[it]){
                dfs(it, adj, visit, st);
            }
        }
        
        st.push(start);
    }
    
    vector<int> topoSort(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> visit(n, 0);
        stack<int> st;
        
        for(int i = 0; i< n; i++){
            if(!visit[i]){
                dfs(i, adj, visit, st);
            }
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};


// ** see the BFS solution which is also known as kahn's algo