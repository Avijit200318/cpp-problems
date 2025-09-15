// *****Permutation in String***
// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

 

// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size(), n = s2.size();
        if(k > n) return false;

        vector<int> hash1(26, 0), hash2(26, 0);

        for(int i = 0; i< k; i++){
            hash1[s1[i] - 'a']++;
            hash2[s2[i] - 'a']++;
        }

        int matches = 0;
        for(int i = 0; i < 26; i++){
            if(hash1[i] == hash2[i]) matches++;
        }

        int left = 0;

        for(int right = k; right < n; right++){
            if(matches == 26) return true;

            // window already created

            // add new element
            hash2[s2[right] - 'a']++;
            if(hash2[s2[right] - 'a'] == hash1[s2[right] - 'a']){
                matches++;
            }
            else if(hash2[s2[right] - 'a'] == hash1[s2[right] - 'a'] + 1){
                matches--;
                // it was priviously matches but not now
            }

            // remove element from front
            hash2[s2[left] - 'a']--;   
            if(hash2[s2[left] - 'a'] == hash1[s2[left] - 'a']){
                matches++;
            }
            else if(hash2[s2[left] - 'a'] == hash1[s2[left] - 'a'] - 1){
                matches--;
                // it was priviously matches but not now
            }
            left++;

            if(matches == 26) return true;
        }

        return matches == 26;
    }
};