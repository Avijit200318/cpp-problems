// Non Repeating Character

// Input: s = "geeksforgeeks"
// Output: 'f'
// Explanation: In the given string, 'f' is the first character in the string which does not repeat.
  
class Solution {
  public:
    Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        int n = s.size();
        map<char, int> mpp;
        for(int i = 0; i< n; i++){
            mpp[s[i]] += 1;
        }
        
        for(int i = 0; i< n; i++){
            if(mpp[s[i]] == 1) return s[i];
        }
        return '$';
    }
    
};
