// Longest Nice Substring -> solved using recursion

// A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.

// Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.

 

// Example 1:

// Input: s = "YazaAay"
// Output: "aAa"
// Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
// "aAa" is the longest nice substring.

class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        if(n < 2) return "";

        map<char, int> mpp;
        for(int i = 0; i< n; i++){
            mpp[s[i]]++;
        }

        for(int i = 0; i< n; i++){
            if(mpp.find(tolower(s[i])) != mpp.end() && mpp.find(toupper(s[i])) != mpp.end()) continue;

            string prev = longestNiceSubstring(s.substr(0, i));
            string next = longestNiceSubstring(s.substr(i+1));

            return prev.size() >= next.size()? prev : next;
        }
        return s;
    }
};