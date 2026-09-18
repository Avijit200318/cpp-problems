// Minimum Window Substring

// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.


class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        map<char, int> mpp;
        map<char, int> window;
        int minLen = INT_MAX;
        int required = 0, formed = 0;
        int left = 0;
        int startIdx = -1;

        if(n == 0 or t.size() == 0) return "";

        for(auto it : t){
            mpp[it]++;
        }

        // number of char required to form substring
        required = mpp.size();

        for(int right = 0; right < n; right++){
            window[s[right]]++;

            // required char to form substring also present in t
            if(mpp.count(s[right]) && window[s[right]] == mpp[s[right]]){
                formed++;
            }

            // when the substring is formed
            while(formed == required){
                // if the current substirn is minimum, then store its size and start idx
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    startIdx = left;
                }

                window[s[left]]--;

                if(mpp.count(s[left]) && window[s[left]] < mpp[s[left]]){
                    formed--;
                }
                left++;
            }
        }
        // if there is no substring present then return empty string
        if(startIdx == -1) return "";
        return s.substr(startIdx, minLen);
    }
};