// Remove All Occurrences of a Substring

// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

// A substring is a contiguous sequence of characters in a string.

 

// Example 1:

// Input: s = "daabcbaabcbc", part = "abc"
// Output: "dab"

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> createLps(string pat){
        int n = pat.size();
        vector<int> lps;
        lps.push_back(0);

        int i = 1, len = 0;
        while(i < n){
            if(pat[i] == pat[len]){
                len++;
                lps.push_back(len);
                i++;
            }
            else{
                if(len != 0){
                    len = lps[len - 1];
                }
                else{
                    lps.push_back(0);
                    i++;
                }
            }
        }
        return lps;
    }

    void removeOccurence(string &s, string pat){
        int n = s.size(), m = pat.size();
        vector<int> lps = createLps(pat);

        int i = 0, j = 0;
        int startIdx = -1;

        while(i < n){
            if(s[i] == pat[j]){
                i++;
                j++;

                if(j == m){
                    s = s.substr(0, i - m) + s.substr(i);
                    n = s.size();
                    i = max(0, i - 2*m);
                    j = 0;
                }
            }
            else{
                if(j != 0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
    }
};

int main(){
    Solution s;
    // string a = "daabcbaabcbc";
    // string pat = "abc";
    string a = "axxxxyyyyb";
    string pat = "xy";
    s.removeOccurence(a, pat);
    cout<<"the answer is: "<<a;
    return 0;
}
