class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int n = s.size();
        int start = 0, count = 1;

        for(int i = 1; i< n; i++){
            if(s[i] == s[i-1]){
                count++;
            }
            else{
                if(count >= 3){
                    ans.push_back({start, i-1});
                }
                start = i;
                count = 1;
            }
        }

        if(count >= 3){
            ans.push_back({start, n-1});
        }        

        return ans;
    }
};
