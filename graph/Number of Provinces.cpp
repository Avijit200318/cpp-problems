// Number of Provinces

// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2

class Solution {
public:
    void helper(int val, vector<vector<int>> &adj, vector<int> &visit){
        visit[val] = 1;

        for(auto it : adj[val]){
            if(!visit[it]){
                helper(it, adj, visit);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n+1);
        vector<int> visit(n+1, 0);
        int count = 0;

        // given matrix convert it to adjecensy list
        // we want 1 based index because the graph starts from index 1.
        for(int i = 1; i< n+1; i++){
            for(int j = 0; j< isConnected[0].size(); j++){
                if(isConnected[i-1][j] == 1 && (i-1) != j){
                    adj[i].push_back(j+1);
                    adj[j+1].push_back(i);
                    // j is starts from 0 so increase it by 1.
                }
            }
        }

        // 1 based index so the loop is started from 1 and go till n
        for(int i = 1; i< n+1; i++){
            if(!visit[i]){
                count++;
                helper(i, adj, visit);
            }
        }

        return count;
    }
};