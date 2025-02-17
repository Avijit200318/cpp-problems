// Letter Tile Possibilities

// You have n  tiles, where each tile has one letter tiles[i] printed on it.

// Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.

 

// Example 1:

// Input: tiles = "AAB"
// Output: 8
// Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
// Example 2:

// Input: tiles = "AAABBC"
// Output: 188

class Solution {
public:
    int helper(vector<int> feq){
        int count = 0;

        for(int i = 0; i< 26; i++){
            if(feq[i] > 0){
                feq[i]--;
                count += 1 + helper(feq);
                feq[i]++;
            }
        }
        return count;
    }

    int numTilePossibilities(string tiles) {
        vector<int> feq(26, 0);
        for(int i = 0; i< tiles.size(); i++){
            feq[tiles[i] - 'A']++;
        }
        return helper(feq);
    }
};
