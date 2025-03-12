// DI String Match
// Example 1:

// Input: s = "IDID"
// Output: [0,4,1,3,2]
// Example 2:

// Input: s = "III"
// Output: [0,1,2,3]
// Example 3:

// Input: s = "DDI"
// Output: [3,2,0,1]

  
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int dVal = n;
        // the first D value will starts from n
        int iVal = 0;
        // the first I value will starts from 0
        vector<int> ans;

        for(int i = 0; i< n; i++){
            if(s[i] == 'I'){
                ans.push_back(iVal);
                iVal++;
            }
            else{
                ans.push_back(dVal);
                dVal--;
            }
        }

        // if the stirng stize is n then the array will be n-1 size. so for the last value we just need to add iVal or Dval both of them are equal.
        ans.push_back(iVal);
        return ans;
    }
};
