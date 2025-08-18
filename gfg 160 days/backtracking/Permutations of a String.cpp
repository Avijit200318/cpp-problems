
    void helper(int idx, int n, string& s, set<string>& ans, string& current, vector<int>& visit){
        if(current.size() == n){
            ans.insert(current);
            return;
        }
        
        for(int i = 0; i< n; i++){
            if(!visit[i]){
                visit[i] = 1;
                current.push_back(s[i]);
                helper(i+1, n, s, ans, current, visit);
                
                visit[i] = 0;
                current.pop_back();
            }
        }
    }
    vector<string> findPermutation(string &s) {
        set<string> ans;
        string current;
        int n = s.size();
        vector<int> visit(n, 0);
        
        helper(0, n, s, ans, current, visit);
        return vector<string>(ans.begin(), ans.end());
    }


// optimal solution
void helper(int idx, int n, string& s, set<string>& ans){
        if(idx == n){
            ans.insert(s);
            return;
        }
        
        for(int i = idx; i< n; i++){
            swap(s[idx], s[i]);
            helper(idx+1, n, s, ans);
            swap(s[idx], s[i]);
        }
    }
    vector<string> findPermutation(string &s) {
        set<string> ans;
        int n = s.size();
        
        helper(0, n, s, ans);
        return vector<string>(ans.begin(), ans.end());
    }
