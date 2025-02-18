// K Closest Points to Origin
// Input: points = [[1,3],[-2,2]], k = 1
// Output: [[-2,2]]
// Explanation:
// The distance between (1, 3) and the origin is sqrt(10).
// The distance between (-2, 2) and the origin is sqrt(8).
// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
// We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multimap<int, int> mpp;
        vector<vector<int>> ans;
        int n = points.size();
        if(n == 0) return ans;

        for(int i =0; i< n; i++){
            int dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            mpp.insert({dis, i});
        }

        for(auto it : mpp){
            if(ans.size() == k) return ans;
            ans.push_back(points[it.second]);
        }
        return ans;
    }
};
