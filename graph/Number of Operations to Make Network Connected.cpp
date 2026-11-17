// Number of Operations to Make Network Connected

// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

// Input: n = 4, connections = [[0,1],[0,2],[1,2]]
// Output: 1
// Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.


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

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);

        int extra = 0;

        // connections are give like (u, v) = u - v
        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            if(ds.findPar(u) == ds.findPar(v)){
                extra++;
            }
            else{
                ds.unionBySize(u, v);
            }
        }


        // now we need to find how many ultimate parent is there
        int up = 0;

        for(int i = 0; i< n; i++){
            if(ds.findPar(i) == i){
                up++;
            }
        }

        if(up - 1 <= extra){
            return up-1;
        }
        return -1;
    }
};