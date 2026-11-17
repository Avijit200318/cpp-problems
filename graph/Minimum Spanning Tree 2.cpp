// Prim's MST

// You are given an undirected connected weighted graph having ‘N’ nodes numbered from 1 to 'N'. A matrix ‘E’ of size M x 2 is given which represents the ‘M’ edges such that there is an edge directed from node E[i][0] to node E[i][1]. You are supposed to return the minimum spanning tree where you need to return weight for each edge in the MST.

// For example :
// Sample Input 1 :
// 1
// 5 14
// 1 2 2
// 1 4 6
// 2 1 2
// 2 3 3
// 2 4 8
// 2 5 5
// 3 2 3
// 3 5 7
// 4 1 6
// 4 2 8
// 4 5 9
// 5 2 5
// 5 3 7
// 5 4 9
// Sample Output 1 :
// 1 2 2
// 1 4 6
// 2 3 3
// 2 5 5
// Explanation of Input 1 :
// The Minimum spanning tree for the given graph will contain the edges: (1,2) with weight 2, (1,4) with weight 6, (2,3) with weight 3 and (2,5) with weight 5.



#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // we have to return it like {{parent, node}, weight}
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
    vector<int> visit(n+1, 0);
    vector<pair<pair<int, int>, int>> mst;
    int sum = 0;

    // first we need to create adjacenty list
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    pq.push({{0, 1}, -1});
    // {{weight, node}, parent}

    while(!pq.empty()){
        auto temp = pq.top();
        pq.pop();

        int node = temp.first.second;
        int weight = temp.first.first;
        int parent = temp.second;

        if(visit[node] == 1) continue;

        // if not visited then perform this
        visit[node] = 1;
        sum += weight;
        // if the parent -1 means the first node
        if(parent != -1){
            mst.push_back({{parent, node}, weight});
        }

        for(auto it : adj[node]){
            int adjNode = it.first;
            int w = it.second;

            if(!visit[adjNode]){
                pq.push({{w, adjNode}, node});
            }
        }
    }
    return mst;
}
