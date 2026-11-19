// Most Stones Removed with Same Row or Column

// On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

// A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

// Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

 

// Example 1:

// Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
// Output: 5
// Explanation: One way to remove 5 stones is as follows:
// 1. Remove stone [2,2] because it shares the same row as [2,1].
// 2. Remove stone [2,1] because it shares the same column as [0,1].
// 3. Remove stone [1,2] because it shares the same row as [1,0].
// 4. Remove stone [1,0] because it shares the same column as [0,0].
// 5. Remove stone [0,1] because it shares the same row as [0,0].
// Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
// Example 2:

// Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
// Output: 3
// Explanation: One way to make 3 moves is as follows:
// 1. Remove stone [2,2] because it shares the same row as [2,0].
// 2. Remove stone [2,0] because it shares the same column as [0,0].
// 3. Remove stone [0,2] because it shares the same row as [0,0].
// Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.


class DisjointSet{
public:
    vector<int> parent, size;
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
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;
        int n = stones.size();
        // n here is number of stones

        for(auto it : stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 1);
        // +1 is extra because our column will go maxRow + maxCol + 1 for maximum value

        unordered_map<int, int> mpp;
        // we need this map to store all the row and col values because 0 no col = 5, 1 no col = 6.. and we need to store them somewhere.

        for(auto it : stones){
            int row = it[0];
            int col = it[1] + maxRow + 1;

            ds.unionBySize(row, col);
            // then store them in the map
            mpp[row] = 1;
            mpp[col] = 1;
        }

        // count ultimate parent then we can just return n - ulpCnt.
        int ulpCnt = 0;

        for(auto it : mpp){
            // if parent[node] == node then that is ultimate parent
            if(ds.findPar(it.first) == it.first){
                ulpCnt++;
            }
        }

        return n - ulpCnt;
    }
};