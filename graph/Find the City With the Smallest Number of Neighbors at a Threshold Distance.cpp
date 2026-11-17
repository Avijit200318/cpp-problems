// Find the City With the Smallest Number of Neighbors at a Threshold Distance

// There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

// Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

// Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

 

// Example 1:



// Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
// Output: 3
// Explanation: The figure above describes the graph. 
// The neighboring cities at a distanceThreshold = 4 for each city are:
// City 0 -> [City 1, City 2] 
// City 1 -> [City 0, City 2, City 3] 
// City 2 -> [City 0, City 1, City 3] 
// City 3 -> [City 1, City 2] 
// Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.


class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // floyed warshall algo
        // creating 2d matrix
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for(auto it : edges){
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        for(int i = 0; i< n; i++){
            dist[i][i] = 0;
        }
        // our matrix is completed

        for(int k = 0; k< n; k++){
            for(int i = 0; i< n; i++){
                for(int j = 0; j< n; j++){
                    // IF it RECHABLE
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        // floyed algo completed


        // set the cntCity a maximum value
        int cntCity = n;
        int city = -1;

        for(int i = 0; i< n; i++){
            int cnt = 0;
            for(int j = 0; j< n; j++){
                if(dist[i][j] <= distanceThreshold){
                    cnt++;
                }
            }

            if(cnt <= cntCity){
                cntCity = cnt;
                city = i;
            }
        }

        return city;
    }
};