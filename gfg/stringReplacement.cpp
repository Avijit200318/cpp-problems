// String Replacement problem gfg

// You are given a string s, containing only charecters 'a' and 'b'. In one operation you can replace sbustring "ab"
// with "bba".Find the minimun number of operation require to make so that no substring "ab" is present in the string s.
// input
// s = "abab"
// output
// 4

class Solution {
  public:
    int countOperations(string s) {
        long long countB = 0;
        long long ans = 0;
        int mod = 1e9+7;
        for(int i = s.size()-1; i >= 0; i--)
        {
            if(s[i] == 'b'){
                countB++;
            }
            else{
                ans = (ans + countB)%mod;
                countB = (countB * 2)%mod;
            }
        }
        return ans;
    }
};
