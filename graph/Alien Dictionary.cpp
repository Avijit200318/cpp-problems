// Alien Dictionary

// An alien language uses the lowercase English alphabet, but the order of its letters is unknown. You are given an array of strings words[] that is claimed to be sorted lexicographically according to the rules of the alien language.

// Determine the order of the letters in the alien alphabet.

// If a valid ordering exists, return a string containing all unique letters in lexicographical order according to the alien language.
// Otherwise, return an empty string.
// If a string s1 is lexicographically smaller than a string s2, and the first position at which they differ contains letter a in s1 and letter b in s2, then a must appear before b in the alien alphabet.
// If one word is a prefix of the other, the shorter word must appear before the longer word.

// Note: The driver code prints true if the returned order is valid; otherwise, it prints false.

// Examples:

// Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
// Output: true
// Explanation: A possible correct order of letters in the alien dictionary is "bdac".
// The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
// The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
// The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
// The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
// So, 'b' -> 'd' -> 'a' -> 'c' is a valid ordering.



class Solution {
  public:
    vector<int> topologySort(int n, vector<vector<int>>& adj, vector<int>& present){
        vector<int> indegree(n, 0);
        
        for(int i = 0; i< n; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        vector<int> ans;
        
        for(int i = 0; i< n; i++){
            if(indegree[i] == 0 && present[i]){
                // if indegree is 0 and the char is present then push them
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        return ans;
    }
  
    string findOrder(vector<string> &words) {
        int n = words.size();
        
        // if we take the size as 26 then during indegree it might take wrong alphablets which did't occur
        // so we need a present list also since number of unique charecters are not given.
        vector<int> present(26, 0);
        int totalUnique = 0;
        
        for(int i = 0; i< n; i++){
            for(char c : words[i]){
                if(!present[c - 'a']){
                    present[c - 'a'] = 1;
                    totalUnique++;
                }
            }
        }
        
        vector<vector<int>> adj(26);
        
        for(int i = 0; i< n-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            
            // Check invalid prefix case: "abc" before "ab"
            if(s1.size() > s2.size() && s1.substr(0, s2.size()) == s2){
                return "";
            }
            
            int minLen = min(s1.size(), s2.size());
            
            for(int j = 0; j< minLen; j++){
                if(s1[j] != s2[j]){
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    // b -> a
                    break;
                }
            }
        }
        
        vector<int> ans = topologySort(26, adj, present);
        // if a cycle present
        if (ans.size() < totalUnique) {
            return "";
        }
        
        string s = "";
        
        for(auto it : ans){
            s += char(it + 'a');
        }
        
        return s;
    }
};