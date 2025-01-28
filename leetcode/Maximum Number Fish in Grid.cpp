//2658. Maximum Number of Fish in a Grid

// Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
// Output: 7
// Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to cell (2,3) and collect 4 fish.

class Solution {
public:
    vector<int> dir = {-1, 0,1, 0,-1};

    bool isValidPos(int x, int y, int n, int m){
        return (x >= 0 && x < n && y >= 0 && y < m);
    }

    int MaxFishFourDirection(vector<vector<int>> arr, vector<vector<bool>>& visited, int x, int y, int n, int m){
        int fishCount = arr[x][y];
        for(int i = 0; i< 4; i++){
            int newX = x + dir[i];
            int newY = y + dir[i+1];
            if(isValidPos(newX, newY, n, m) && !visited[newX][newY] && arr[newX][newY] > 0){
                visited[newX][newY] = true;
                fishCount += MaxFishFourDirection(arr, visited, newX, newY, n, m);
            }
        }
        return fishCount;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxFish = 0;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i = 0; i< n; i++){
            for(int j = 0; j< m; j++){
                if(!visited[i][j] && grid[i][j] != 0){
                    visited[i][j] = true;
                    maxFish = max(maxFish, MaxFishFourDirection(grid, visited, i, j, n, m));
                }
            }
        }
        return maxFish;
    }
};
