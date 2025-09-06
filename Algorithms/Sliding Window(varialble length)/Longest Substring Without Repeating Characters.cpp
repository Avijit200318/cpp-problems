// 2. Longest Substring Without Repeating Characters
// Given a string s, find the length of the longest substring without duplicate characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mpp;
        int n = s.size();
        int left = 0, length = 0;

        for(int right = 0; right< n; right++){
            // if there is an duplicate element present then remove it and increase the value of left.
            while(mpp.find(s[right]) != mpp.end()){
                mpp.erase(s[left]);
                left++;
            }

            // insert the right value inside the map
            mpp[s[right]]++;
            length = max(right - left + 1, length);
        }
        return length;
    }
};