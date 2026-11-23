// Critical Connections in a Network

// There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

// A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

// Return all critical connections in the network in any order.

// Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
// Output: [[1,3]]
// Explanation: [[3,1]] is also accepted.
// Example 2:

// Input: n = 2, connections = [[0,1]]
// Output: [[0,1]]


class Solution {
private:
    int timer = 1;
    // set it 1 then we will increase it
public:
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& visit, vector<int>& time, vector<int>& low, vector<vector<int>>& ans){
        visit[node] = 1;
        time[node] = timer;
        low[node] = timer;

        timer++;

        for(auto it : adj[node]){
            // if it is parent where it actually came from ignore it
            if(it == parent) continue;

            if(!visit[it]){
                // if not visit then dfs and go
                dfs(it, node, adj, visit, time, low, ans);
                // after this dfs is done for node it. we need to chceck minimum of low
                low[node] = min(low[node], low[it]);
                // then we need to check are they bridge or not (node --- it)
                if(low[it] > time[node]){
                    // means it bridge
                    ans.push_back({node, it});
                }
            }
            else{
                // if it already visited then change the low only.
                low[node] = min(low[node], low[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // first we need to create adj list
        vector<vector<int>> adj(n);

        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visit(n, 0);
        vector<int> time(n), low(n);

        vector<vector<int>> ans;

        dfs(0, -1, adj, visit, time, low, ans);
        // (node, parent, adj, visit, time, low, ans)
        return ans;
    }
};