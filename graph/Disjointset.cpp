// Disjointset

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent, rank, size;
    public:
    // create constructor
    DisjointSet(int n){
        // if we use n+1 size then it will work for both the 0 and 1 index graph
        parent.resize(n+1, 0);
        rank.resize(n+1, 0);
        size.resize(n+1, 1);

        for(int i = 0; i<= n; i++){
            parent[i] = i;
        }
    }

    // now two functions
    int findPar(int node){
        if(node == parent[node]) return node;

        return parent[node] = findPar(parent[node]);
    }


    void unionByRank(int u, int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        // if both have same parent then just return
        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]){
            // smaller rank element will added to larger rank. so the parent of smaller rank will be change to the ultimate parent of bigger rank
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_v;
        }
        else{
            // if both have same rank we can add anyone of them.
            parent[ulp_v] = ulp_u;
            // or we can do the opposite
            // since the ulp_u is our ultimate parent so we need to increase its rank, since height will increase after new branch is added.
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if(ulp_v == ulp_u) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            // here we have oposite case as well as same case both of them same
            // because in same case we can choose any one of them as parent
            parent[ulp_v] = parent[ulp_u];
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main(){
    // use of the class or datastructure
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // if 3 and 7 same or not
    if(ds.findPar(3) == ds.findPar(7)){
        cout<<"same"<<endl;
    }
    else{
        cout<<"Not same"<<endl;
    }

    ds.unionByRank(3, 7);
    if(ds.findPar(3) == ds.findPar(7)){
        cout<<"same"<<endl;
    }
    else{
        cout<<"Not same"<<endl;
    }

    return 0;
}


// don't use union by rank and union by size together. use any one of them at a time.