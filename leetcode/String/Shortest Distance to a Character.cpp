// Shortest Distance to a Character

// Example 1:

// Input: s = "loveleetcode", c = "e"
// Output: [3,2,1,0,1,0,0,1,2,2,1,0]
// Explanation: The character 'e' appears at indices 3, 5, 6, and 11 (0-indexed).
// The closest occurrence of 'e' for index 0 is at index 3, so the distance is abs(0 - 3) = 3.
// The closest occurrence of 'e' for index 1 is at index 3, so the distance is abs(1 - 3) = 2.
// For index 4, there is a tie between the 'e' at index 3 and the 'e' at index 5, but the distance is still the same: abs(4 - 3) == abs(4 - 5) = 1.
// The closest occurrence of 'e' for index 8 is at index 6, so the distance is abs(8 - 6) = 2.
// Example 2:

// Input: s = "aaab", c = "b"
// Output: [3,2,1,0]

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> hash;
        int n = s.size();
        vector<int> ans(n, 0);

        for(int i = 0; i< n; i++){
            if(s[i] == c) hash.push_back(i);
        }

        if(hash.size() == n) return ans;

        for(int i = 0; i< n; i++){
            int minVal = INT_MAX;
            for(int j = 0; j< hash.size(); j++){
                minVal = min(abs(hash[j] - i), minVal);
            }
            ans[i] = minVal;
        }
        return ans;
    }
};
