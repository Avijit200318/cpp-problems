//{ Driver Code Starts
// Anagram
// Difficulty: EasyAccuracy: 44.93%Submissions: 377K+Points: 2
// Given two strings s1 and s2 consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, "act" and "tac" are an anagram of each other. Strings s1 and s2 can only contain lowercase alphabets.

// Note: You can assume both the strings s1 & s2 are non-empty.

// Examples :

// Input: s1 = "geeks", s2 = "kseeg"
// Output: true
// Explanation: Both the string have same characters with same frequency. So, they are anagrams.

// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    // bool areAnagrams(string& s1, string& s2) {
    //     int n = s1.size(), m = s2.size();
    //     if(n != m) return false;
    //     map<char, int> mpp1, mpp2;
    //     for(int i = 0; i< n; i++)
    //     {
    //         mpp1[s1[i]] += 1;
    //         mpp2[s2[i]] += 1;
    //     }
        
    //     for(int i = 0; i< n; i++){
    //         if(mpp2.find(s1[i]) == mpp2.end() || mpp1[s1[i]] != mpp2[s1[i]]){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    
    bool areAnagrams(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        if(n != m) return false;
        map<char, int> mpp;
        for(int i = 0; i< n; i++)
        {
            mpp[s1[i]] += 1;
        }
        
        for(int i = 0; i< n; i++){
            if(mpp.find(s2[i]) == mpp.end()){
                return false;
            }
            else{
                mpp[s2[i]] -= 1;
            }
        }
        
        for(auto it : mpp){
            if(it.second != 0) return false;
        }
        return true;
    }
};
