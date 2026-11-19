// Making A Large Island

// You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

// Return the size of the largest island in grid after applying this operation.

// An island is a 4-directionally connected group of 1s.

 

// Example 1:

// Input: grid = [[1,0],[0,1]]
// Output: 3
// Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
// Example 2:

// Input: grid = [[1,1],[1,0]]
// Output: 4
// Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
// Example 3:

// Input: grid = [[1,1],[1,1]]
// Output: 4
// Explanation: Can't change any 0 to 1, only one island with area = 4.
 

class DisjointSet{
public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1, 0);
        size.resize(n+1, 1);

        for(int row = 0; row<= n; row++){
            parent[row] = row;
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        // step 1 connect everyone
        for(int row = 0; row< n; row++){
            for(int col = 0; col< n; col++){
                // if it island then we can connect them
                if(grid[row][col] == 1){
                    
                    // traverse all the 4 directions
                    for(int idx = 0; idx < 4; idx++){
                        int r = row + delRow[idx];
                        int c = col + delCol[idx];

                        if(r >= 0 && r < n && c >= 0 && c < n){
                            // check if new r c cell is an island or not
                            if(grid[r][c] == 1){
                                int node = row * n + col;
                                int adjNode = r * n + c;

                                ds.unionBySize(node, adjNode);
                            }
                        }
                    }   
                }
            }
        }

        // step 2: replace all the 0 -> 1 and check
        int maxVal = 0;

        for(int row = 0; row < n; row++){
            for(int col = 0; col< n; col++){
                if(grid[row][col] == 0){
                    set<int> st;
                    for(int i = 0; i< 4; i++){
                        int r = row + delRow[i];
                        int c = col + delCol[i];

                        if(r >= 0 && r < n && c >= 0 && c < n){
                            // new row, col is valid and there is an island then store its ultimate parent in a set
                            if(grid[r][c] == 1){
                                int node = r * n + c;
                                st.insert(ds.findPar(node));
                            }
                        }
                    }

                    int sum = 0;
                    for(auto it : st){
                        sum += ds.size[it];
                    }
                    sum += 1;
                    maxVal = max(maxVal, sum);
                }
            }
        }

        // still there is an edge case if all the value is 1. then we need to traverse each cell and compare maxVal with each cell size[]
        for(int i = 0; i< n * n; i++){
            maxVal = max(maxVal, ds.size[i]);
        }

        return maxVal;
    }
};