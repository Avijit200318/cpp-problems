// Number of Islands II / Count Islands After Every Operation

// Given a grid of n rows and m columns. Initially, all cells of the grid contain 0, where 0 represents water.

// You are also given a 2D array operators[][], where each operator contains two integers representing the row and column of a cell.
// Each operation converts the specified water cell into land by changing its value from 0 to 1.
// Return an array containing the number of islands after each operation.

// An island is a group of one or more land cells (or 1s) with the following properties,

// 1s are connected through their top, bottom, left, or right sides.
// Diagonally connected are not considered part of the same island.
// Examples:

// Input: n = 4, m = 4, operators[][] = [[1, 1], [0, 1], [3, 2], [3, 3]]
// Output: [1, 1, 2, 2]
// Explanation: Grid after each operation are shown below.


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

        return  parent[node] = findPar(parent[node]);
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n * m);
        vector<vector<int>> visit(n, vector<int>(m, 0));
        int cnt = 0;
        
        vector<int> ans;
        
        for(auto it : operators){
            int row = it[0];
            int col = it[1];
            
            // if it visited then just push cnt and continue
            if(visit[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }
            
            // if it not visit then increase cnt and update visit
            cnt++;
            visit[row][col] = 1;
            
            // we need to check 4 directions
            vector<int> delRow = {-1, 0, 1, 0};
            vector<int> delCol = {0, 1, 0, -1};
            
            for(int i = 0; i< 4; i++){
                int r = row + delRow[i];
                int c = col + delCol[i];
                
                // new row colum validity
                if(r >= 0 && r < n && c >= 0 && c < m){
                    // island present
                    if(visit[r][c] == 1){
                        // now we have to calculate nodes
                        int node = row * m + col;
                        int adjNode = r * m + c;
                        
                        // if ndoe and adjNode have diff parent then reduct cnt and join them
                        if(ds.findPar(node) != ds.findPar(adjNode)){
                            cnt--;
                            ds.unionBySize(node, adjNode);
                        }
                    }
                }
            }
            // all the 4 directional checking done then add cnt to ans
            ans.push_back(cnt);
        }
        return ans;
    }
};