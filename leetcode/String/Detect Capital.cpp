// Detect Capital

// We define the usage of capitals in a word to be right when one of the following cases holds:

// All letters in this word are capitals, like "USA".
// All letters in this word are not capitals, like "leetcode".
// Only the first letter in this word is capital, like "Google".
// Given a string word, return true if the usage of capitals in it is right.

 

// Example 1:

// Input: word = "USA"
// Output: true
// Example 2:

// Input: word = "FlaG"
// Output: false


class Solution {
public:
    bool detectCapitalUse(string word) {
        int noCap = 0;
        int firstCapIdx = -1;
        int n = word.size();

        for(int i = 0; i< n; i++){
            if(word[i] >= 'A' && word[i] <= 'Z'){
                noCap++;
                if(firstCapIdx == -1) firstCapIdx = i;
            }
        }

        if(noCap == 0 || noCap == n || noCap == 1 && (firstCapIdx <= 0)) return true;
        return false;
    }
};
