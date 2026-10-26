// // DFS Traversal

// Given an undirected and disconnected graph G(V, E), containing 'V' vertices and 'E' edges, the information about edges is given using 'GRAPH' matrix, where i-th edge is between GRAPH[i][0] and GRAPH[i][1]. print its DFS traversal.

// V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 

// E is the number of edges present in graph G.
// Note :
// The Graph may not be connected i.e there may exist multiple components in a graph.

// Sample Input 1:
// 5 4
// 0 2
// 0 1
// 1 2
// 3 4
// Sample Output 1:
// 2
// 0 1 2
// 3 4
// Explanation For Sample Input 1:
// If we do a DFS traversal from vertex 0 we will get a component with vertices [0, 2, 1]. If we do a DFS traversal from 3 we will get another component with vertices [3, 4]

// Hence,  we have two disconnected components so on the first line, print 2. Now, print each component in increasing order. On the first line print 0 1 2 and on the second line, print 3 4.

// [0 1 2] comes before [3 4] as the first vertex 0 from the first component is smaller than the first vertex 3 from the second component.


void helper(int val, vector<vector<int>> &adj, vector<int> &visit, vector<int> &current){
    visit[val] = 1;
    current.push_back(val);

    for(auto it : adj[val]){
        if(!visit[it]){
        helper(it, adj, visit, current);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    vector<int> visit(V, 0);
    vector<vector<int>> adj(V);

    // we are given the eges so first create an adj metrix.
    for(int i = 0; i< E; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // start from the first visited list and check each of them to get all the unconnected graph
    for(int i = 0; i< V; i++){
        if(!visit[i]){
            vector<int> current;
            helper(i, adj, visit, current);
            sort(current.begin(), current.end());
            ans.push_back(current);
        }
    }
    return ans;
}