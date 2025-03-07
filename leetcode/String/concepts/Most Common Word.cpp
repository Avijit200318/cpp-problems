// Most Common Word
// Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer is unique.

// The words in paragraph are case-insensitive and the answer should be returned in lowercase.

 

// Example 1:

// Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
// Output: "ball"
// Explanation: 
// "hit" occurs 3 times, but it is a banned word.
// "ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
// Note that words in the paragraph are not case sensitive,
// that punctuation is ignored (even if adjacent to words, such as "ball,"), 
// and that "hit" isn't the answer even though it occurs more because it is banned.
// Example 2:

// Input: paragraph = "a.", banned = []
// Output: "a"

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string s = "";
        for(auto it : paragraph){
            s += isalpha(it)? tolower(it) : ' ';
          // this line eleminate any char which is not an alphabet. and to lower help to convert uppercase to lowercase (if it already lowercase then it just print that)
        }

        unordered_set<string> st(banned.begin(), banned.end());
        unordered_map<string, int> mpp;

        string s1;
      // this sting variable we need to get each strings from string stream
        stringstream ss(s);
        // string stream -> "1 2 3 4 5 6"
      
        string ans = "";
      
        int maxOccur = 0;
        while(ss >> s1){
          // this line help us to get each stream string(example 1 then 2 then 3 and so on)
            mpp[s1]++;
            if(maxOccur < mpp[s1] && (st.find(s1) == st.end())){
                maxOccur = mpp[s1];
                ans = s1;
            }
        }

        return ans;
    }
};
