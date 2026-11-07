// Path With Minimum Effort

// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

// Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 
// Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
// Output: 2
// Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
// This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
// Example 2:



// Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
// Output: 1
// Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
// Example 3:


// Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
// Output: 0
// Explanation: This route does not require any effort.


class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // {dis, {row, col}}
        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));

        pq.push({0, {0, 0}});
        dis[0][0] = 0;

        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int d = it.first;
            int row = it.second.first;
            int col = it.second.second;

            // if we find the destination for first time then return the vlaue
            if(row == n-1 && col == m-1) return d;

            for(int i = 0; i< 4; i++){
                int r = row + delRow[i];
                int c = col + delCol[i];

                if(r >= 0 && r < n && c >= 0 && c < m){
                    // check effort which is maximum of all and difference between values
                    int effort = max(abs(heights[row][col] - heights[r][c]), d);
                    if(effort < dis[r][c]){
                        dis[r][c] = effort;
                        pq.push({effort, {r, c}});
                    }
                }
            }
        }
        return -1;
    }
};