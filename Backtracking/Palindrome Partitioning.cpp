//  Palindrome Partitioning

// Companies
// Given a string s, partition s such that every substring of the partition is a palindrome. 
// Return all possible palindrome partitioning of s.

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]

class Solution {
public:
    bool isPlaindrome(string s, int start, int end){
        int i = start;

        while(i <= end){
            if(s[i] != s[end]) return false;
            i++;
            end--;
        }
        return true;
    }

    void solve(int idx, int n, string &s, vector<vector<string>> &ans, vector<string> &current){
        if(idx == n){
            ans.push_back(current);
            return;
        }

        for(int i = idx; i< n; i++){
            if(isPlaindrome(s, idx, i)){
                current.push_back(s.substr(idx, i - idx + 1));
                solve(i+1, n, s, ans, current);

                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> current;
        int n = s.size();

        solve(0, n, s, ans, current);
        return ans;
    }
};
