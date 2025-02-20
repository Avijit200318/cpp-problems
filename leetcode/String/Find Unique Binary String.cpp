// Find Unique Binary String

// Example 1:

// Input: nums = ["01","10"]
// Output: "11"
// Explanation: "11" does not appear in nums. "00" would also be correct.
// Example 2:

// Input: nums = ["00","01"]
// Output: "11"
// Explanation: "11" does not appear in nums. "10" would also be correct.

class Solution {
public:
    string solve(int n, map<string, int>& mpp, string &s){
        if(s.size() == n){
            if(mpp.find(s) == mpp.end()) return s;
            return "";
        }

        s.push_back('0');
        string res = solve(n, mpp, s);
        if(res.size() != 0) return res;

        s.pop_back();
        s.push_back('1');
        res = solve(n, mpp, s);
        if(res.size() != 0) return res;
        s.pop_back();
        return "";
    }

    string findDifferentBinaryString(vector<string>& nums) {
        string s = "";
        map<string, int> mpp;
        int n = nums.size();

        for(int i = 0; i<n; i++){
            mpp[nums[i]]++;
        }

        return solve(n, mpp, s);
    }
};
