// Search Pattern (KMP-Algorithm)
// Difficulty: HardAccuracy: 45.04%Submissions: 102K+Points: 8
// Given two strings, one is a text string txt and the other is a pattern string pat. The task is to print the indexes of all the occurrences of the pattern string in the text string. Use 0-based indexing while returning the indices. 
// Note: Return an empty list in case of no occurrences of pattern.

// Examples :

// Input: txt = "abcab", pat = "ab"
// Output: [0, 3]
// Explanation: The string "ab" occurs twice in txt, one starts at index 0 and the other at index 3. 

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // vector<int> searchPattern(string text, string pat){
    //     int n = text.size(), m = pat.size();
    //     vector<int> ans;

    //     for(int i = 0; i< n; i++){
    //         if(text[i] == pat[0]){
    //             int start = i;
    //             int j = i+1, k = 1;
    //             while(j < n && k < m){
    //                 if(text[j] != text[k]) break;
    //                 j++;
    //                 k++;
    //             }
    //             if(k == m){
    //                 ans.push_back(start);
    //             }
    //         }
    //     }
    //     return ans;
    // }

// generate lps
    vector<int> createLps(string pat){
        int n =pat.size();
        vector<int> lps;
        lps.push_back(0);
        
        int i = 1, len = 0;
        while(i < n){
            if(pat[len] == pat[i]){
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

// kmp algorightm for pattern matching
    vector<int> searchPattern(string text, string pat){
        int n= text.size(), m = pat.size();
        vector<int> ans, lps;
        lps = createLps(pat);
        
        int i = 0, j = 0;
        while(i < n){
            if(text[i] == pat[j]){
                i++;
                j++;
                
                if(j == m){
                    ans.push_back(i - j);
                    j = lps[j-1];
                }
            }
            else{
                if(j != 0){
                    j = lps[j - 1];
                }
                else{
                    i++;
                }
            }
        }
        return ans;
    }
};
// tiem complexity o(m + n)

int main(){
    Solution s;
    vector<int> a = s.searchPattern("abcab", "ab");
    // vector<int> a = s.searchPattern("abesdu", "edu");
    // vector<int> a = s.searchPattern("aabaacaadaabaaba", "aaba");
    for(int i = 0; i< a.size(); i++){
        cout<< a[i] << " ";
    }
    return 0;
}
