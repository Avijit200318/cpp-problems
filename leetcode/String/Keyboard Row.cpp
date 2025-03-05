// 500. Keyboard Row
// Solved
// Easy
// Topics
// Companies
// Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.

// Note that the strings are case-insensitive, both lowercased and uppercased of the same letter are treated as if they are at the same row.

// In the American keyboard:

// the first row consists of the characters "qwertyuiop",
// the second row consists of the characters "asdfghjkl", and
// the third row consists of the characters "zxcvbnm".

//   Example 1:

// Input: words = ["Hello","Alaska","Dad","Peace"]

// Output: ["Alaska","Dad"]

// Explanation:

// Both "a" and "A" are in the 2nd row of the American keyboard due to case insensitivity.

// Example 2:

// Input: words = ["omk"]

// Output: []

// Example 3:

// Input: words = ["adsdf","sfd"]

// Output: ["adsdf","sfd"]

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> mpp;

        string s1 = "qwertyuiop", s2 = "asdfghjkl", s3 = "zxcvbnm";

        for(auto it: s1) mpp[it] = 1;
        for(auto it: s2) mpp[it] = 2;
        for(auto it: s3) mpp[it] = 3;

        int n = words.size();
        vector<string> ans;

        for(int i = 0; i< n; i++){
            int prev = 0;
            bool flag = true;
            for(int j = 0; j< words[i].size(); j++){
                if(prev == 0){
                    if(words[i][j] >= 'A' && words[i][j] <= 'Z'){
                        prev = mpp[tolower(words[i][j])];
                    }
                    else{
                        prev = mpp[words[i][j]];
                    }
                }
                else{
                    if(words[i][j] >= 'A' && words[i][j] <= 'Z'){
                        if(prev != mpp[tolower(words[i][j])]){
                            flag = false;
                            break;
                        }
                    }
                    else{
                        if(prev != mpp[words[i][j]]) {
                            flag = false;
                            break;
                        }
                    }
                }
            }

            if(flag == true) ans.push_back(words[i]);
        }
        return ans;
    }
};
