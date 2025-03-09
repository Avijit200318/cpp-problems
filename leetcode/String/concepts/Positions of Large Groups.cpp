class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        // i and j will start from the 0th index. but i will increment as i = j as jth value. here i will store the first occurence and j will store the last occurance.
        // if s[i] and s[j] is equal then j++
        // means consicutive charecters
        // and lastly we will check if j - i is >= 3
        // if is not then set i = j
        for(int i = 0, j = 0; i< s.size(); i = j){
            while(j < s.size() && s[i] == s[j]) j++;
            if(j - i >= 3){
                ans.push_back({i, j-1});
            }
        }
        return ans;
    }
};
