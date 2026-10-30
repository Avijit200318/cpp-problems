// Find Eventual Safe States

// There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

class Solution {
public:
    bool dfs(int start, vector<vector<int>>& graph, vector<int>& visit, vector<int>& pathVisit, vector<int>& checkList){
        visit[start] = 1;
        pathVisit[start] = 1;

        for(auto it : graph[start]){
            if(!visit[it]){
                if(dfs(it, graph, visit, pathVisit, checkList) == true){
                    // part of cycle so add checkList to 0
                    checkList[it] = 0;
                    return true;
                }
            }
            else if(pathVisit[it]){
                checkList[it] = 0;
                return true;
            }
        }

        // if it not part of cycle then we will remove the pathVisit also add checkList to 1
        pathVisit[start] = 0;
        checkList[start] = 1;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int> checkList(n, 0);
        vector<int> visit(n, 0);
        vector<int> pathVisit(n, 0);

        for(int i = 0; i< n; i++){
            if(!visit[i]){
                dfs(i, graph, visit, pathVisit, checkList);
            }
        }

        for(int i = 0; i< n; i++){
            if(checkList[i] == 1){
                ans.push_back(i);
            }
        }

        return ans;
    }
};