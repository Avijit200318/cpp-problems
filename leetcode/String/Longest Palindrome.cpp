// Longest Palindrome

// Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
// palindrome
//  that can be built with those letters.

// Letters are case sensitive, for example, "Aa" is not considered a palindrome.

 

// Example 1:

// Input: s = "abccccdd"
// Output: 7
// Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size() == 0) return 0;
        if(s.size() == 1) return 1;
        map<char, int> mpp;
        for(int i = 0; i< s.size(); i++){
            mpp[s[i]]++;
        }

        int count = 0;
        for(auto it : mpp){
            count += (it.second / 2) * 2;
            if(count % 2 == 0 && it.second % 2 == 1){
                count++;
            }
        }
        return count;
    }
};
