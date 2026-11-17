// Number of Provinces using Disjoint set

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
        if(parent[node] == node) return node;

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
            size[ulp_u] += size[ulp_v];
        }
    }
};

int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    DisjointSet ds(n);

    // start 0 index because we want to traverse the matrix
    for(int i = 0; i< n; i++){
        for(int j = 0; j< n; j++){
            if(roads[i][j] == 1){
                // since the graph is start by 1 based index so during unitonBySize we need to increase the indexes by 1
                ds.unionBySize(i+1, j+1);
            }
        }
    }


    int cnt = 0;
    // since the graph is 1 index based
    for(int i = 1; i<= n; i++){
        if(ds.findPar(i) == i){
            cnt++;
        }
    }
    return cnt;
}