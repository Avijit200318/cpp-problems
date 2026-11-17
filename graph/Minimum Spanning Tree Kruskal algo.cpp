// Minimum Spanning Tree - using Kruskal algo

class DisjointSet{
    vector<int> parent, size;
    public:
    DisjointSet(int n){
        parent.resize(n+1, 0);
        size.resize(n+1, 1);
        
        for(int i = 0; i<= n; i++){
            parent[i] = i;
        }
    }
    
    int findPar(int node){
        if(node == parent[node]) return node;
        
        return parent[node] = findPar(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        
        if(ulp_u == ulp_v) return;
        
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += ulp_v;
        }
    }
};

class Solution {
  public:
    int primMST(vector<vector<vector<int>>> &adj) {
        // convert adj into vector or pairs
        vector<pair<int, pair<int, int>>> edges;
        // {weight, {u, v}}
        
        for(int i = 0; i< adj.size(); i++){
            // adj[i] = [[1, 5], [2, 1]]
            // so we need one more loop
            for(auto it : adj[i]){
                int u = i;
                int v = it[0];
                int w = it[1];
                
                edges.push_back({w, {u, v}});
                edges.push_back({w, {v, u}});
                // since it bidirectional graph and algo will ignore one of them
                // if we want we can use a single edges here
            }
        }
        
        sort(edges.begin(), edges.end());
        
        // useing DisjointSet class or datastructure
        DisjointSet ds(adj.size());
        // perform kruskal algo
        int sum = 0;
        
        for(auto it : edges){
            int w = it.first;
            int node = it.second.first;
            int adjNode = it.second.second;
            
            if(ds.findPar(node) != ds.findPar(adjNode)){
                sum += w;
                ds.unionBySize(node, adjNode);
            }
        }
        
        return sum;
    }
};

// time complexity: o(m + e) + o(mlogm) + o(m * 4 * alpha)