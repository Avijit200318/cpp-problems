// Construct the Lexicographically Largest Valid Sequence

// Example 1:

// Input: n = 3
// Output: [3,1,2,3,2]
// Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the lexicographically largest valid sequence.
// Example 2:

// Input: n = 5
// Output: [5,3,1,4,3,5,2,4,2]

class Solution {
public:
    bool solve(int idx, int n, vector<bool> &visit, vector<int> &res){
        if(idx >= res.size()) return true;

        if(res[idx] != -1) return solve(idx+1, n, visit, res);

        for(int i = n; i>= 1; i--){
            if(visit[i]) continue;

            res[idx] = i;
            visit[i] = true;

            if(i == 1){
                if(solve(idx+1, n, visit, res)) return true;
            }
            else{
                int j = i + idx;
                if(j < res.size() && res[j] == -1){
                    res[j] = i;
                    if(solve(idx+1, n, visit, res)) return true;
                    res[j] = -1;
                }
            }
            res[idx] = -1;
            visit[i] = false;
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> res(n*2 - 1, -1);
        vector<bool> visit(n, false);

        solve(0, n, visit, res);
        return res;
    }
};
