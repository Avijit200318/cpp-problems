// Uncommon Words from Two Sentences


class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss1(s1);
        stringstream ss2(s2);
        string s = "";

        map<string, int> mpp;

        while(ss1 >> s){
            mpp[s]++;
        }

        while(ss2 >> s){
            mpp[s]++;
        }

        vector<string> ans;

        for(auto it : mpp){
            if(it.second == 1){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
