// 3.  Longest Repeating Character Replacement

// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

// Example 1:

// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.
// Example 2:

// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
// There may exists other ways to achieve this answer too

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        map<char, int> mpp;
        int left = 0, length = 0;

        for(int right = 0; right < n; right++){
            mpp[s[right]]++;
            
            //highest takes 0(26) time to find maxOccur of charecters
            int maxOccur = 0;
            for(auto it : mpp){
                maxOccur = max(maxOccur, it.second);
            }

            // current window size is greater than the vlaue of k
            // window_size - maxOccurence if greater then k then reduce the size of window
            while((right - left + 1) - maxOccur > k){
                mpp[s[left]]--;
                left++;
            }

            length = max(length, right - left +1);
        }
        return length;
    }
};