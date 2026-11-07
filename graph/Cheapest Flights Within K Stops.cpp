// Cheapest Flights Within K Stops

// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 

// Example 1:


// Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
// Output: 700
// Explanation:
// The graph is shown above.
// The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
// Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for(int i = 0; i< flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            adj[u].push_back({v, w});
        }

        queue<pair<int, pair<int , int>>> q;
        vector<int> dis(n, INT_MAX);

        q.push({0, {src, 0}});
        // {step, {src, cost}}
        dis[src] = 0;

        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int steps = temp.first;
            int node = temp.second.first;
            int weight = temp.second.second;

            // if steps > k then ignore
            if(steps > k) continue;

            for(auto it : adj[node]){
                int adjNode = it.first;
                int w = it.second;

                if(w + weight < dis[adjNode] && steps <= k){
                    dis[adjNode] = w + weight;
                    q.push({steps + 1, {adjNode, w + weight}});
                }
            }
        }


        if(dis[dst] == INT_MAX) return -1;
        return dis[dst];
    }
};