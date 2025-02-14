// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string res = "";
        for(int i = 0; i< n; i++){
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i]) >= '0' && s[i] <= '9'){
                if(s[i] >= 'A' && s[i] <= 'Z'){
                    res.push_back(s[i]+32);
                }
                else{
                    res.push_back(s[i]);
                }
            }
        }
        string s1 = res;
        reverse(s1.begin(), s1.end());
        return s1 == res;
    }
};
