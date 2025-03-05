// 541. Reverse String II
// Solved
// Easy
// Topics
// Companies
// Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

// If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.

 

// Example 1:

// Input: s = "abcdefg", k = 2
// Output: "bacdfeg"
// Example 2:

// Input: s = "abcd", k = 2
// Output: "bacd"


class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        
        if(s.size() <= k) {
            reverse(s.begin(), s.end());
            return s;
        }

        for(int i = 0; i< n; i += 2*k){
            if(i + k < n) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};
