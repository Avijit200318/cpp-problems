// Number of Ways to Arrive at Destination

// You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

// You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

// Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = (int)(1e9 + 7);
        vector<vector<pair<int, int>>> adj(n);

        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<long long> dis(n, 1e18);
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        dis[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()){
            long long weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // optimization
            if (weight > dis[node]) continue;

            for(auto it : adj[node]){
                int adjNode = it.first;
                long long w = it.second;

                // check if its the fist time we reach this node
                if(w + weight < dis[adjNode]){
                    dis[adjNode] = w + weight;
                    pq.push({w + weight, adjNode});
                    // we will set ways as from which node we go adjNode
                    ways[adjNode] = ways[node];
                }
                else if(w + weight == dis[adjNode]){
                    // if we reach this node previously with same dis
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};