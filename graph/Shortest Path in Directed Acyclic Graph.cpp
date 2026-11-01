// Shortest Path in Directed Acyclic Graph

// Given a Directed Acyclic Graph (DAG) with V vertices numbered from 0 to V - 1 and weighted directed edges represented by a 2D array edges[][], where edges[i] = [u, v, wt] denotes a directed edge from vertex u to vertex v with weight wt, find the shortest distance from the source vertex 0 to every other vertex.

// Return an array of size V, where the i-th element represents the shortest distance from the source vertex 0 to vertex i. If a vertex is not reachable from the source, return -1 for that vertex.

// Examples :

// Input: V = 4, edges = [[0,1,2], [0,2,1]]
// Output: [0, 2, 1, -1]
// Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->2 with edge weight 1. There is no way we can reach 3, so it's -1 for 3.

class Solution {
	public:
	void dfs(int node, vector<vector<pair<int, int>>>& adj, vector<int>& visit, stack<int>& st) {
		visit[node] = 1;
		
		for (auto it : adj[node]) {
			if (!visit[it.first]) {
				dfs(it.first, adj, visit, st);
			}
		}
		
		st.push(node);
	}
	
	vector<int> shortestPath(int V, vector<vector<int>> & edges) {
		// create the adj
		vector<vector<pair<int, int>> > adj(V);
		
		for (int i = 0; i<edges.size(); i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			int w = edges[i][2];
			
			adj[u].push_back({v, w});
		}
		
		// topological sort
		vector<int> visit(V, 0);
		stack<int> st;
		
		for (int i = 0; i<V; i++) {
			if (!visit[i]) {
				dfs(i, adj, visit, st);
			}
		}
		
		// all the values are stored in stack
		
		// step2:
		vector<int> dis(V, INT_MAX);
		
		// set the source value to 0
		dis[0] = 0;
		
		while (!st.empty()) {
			int node = st.top();
			st.pop();
			
            // if the current node distance is INT_MAX means it is not reachable so for that don't run this loop
			if (dis[node] != INT_MAX) {
				for (auto it : adj[node]) {
					int v = it.first;
					int w = it.second;
					
					if (dis[node] + w < dis[v]) {
						dis[v] = dis[node] + w;
					}
				}
			}
		}
		
        // questions says if it not reachable then set it to -1
		for (int i = 0; i < V; i++) {
              if (dis[i] == INT_MAX) {
                  dis[i] = -1;
              }
          }
		
		return dis;
	}
};
