//Add Binary Strings

// Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
// Note: The input strings may contain leading zeros but the output string should not have any leading zeros.

// Input: s1 = "1101", s2 = "111"
// Output: 10100
// Explanation:
//  1101
// + 111
// 10100


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
  string removeZero(string s){
    int n = s.size(), idx = -1;

    for(int i = 0; i< n; i++){
        if(s[i] == '1'){
            idx = i;
            break;
        }
    }
    if(idx == -1) return "";
    s = s.substr(idx, n - idx);
    return s;
  }
  
    string addBinary(string& s1, string& s2) {
        s1 = removeZero(s1);
        s2 = removeZero(s2);
        int n = s1.size();
        int m = s2.size();
        if(s1 == "") return s2;
        if(s2 == "") return s1;
        if(n < m) return addBinary(s2, s1);
        
        int carry = 0, bitsum = 0, sum = 0, j = m-1;
        vector<int> ans;
        for(int i = n-1; i >= 0; i--){
            sum = s1[i] - '0';
            sum += carry;
            
            if(j >= 0){
                sum += (s2[j] - '0');
                j--;
            }
            
            ans.push_back(sum % 2);
            carry = sum / 2;
            
            
        }
        if(carry > 0){
            ans.push_back(carry);
        }
        
        string s = "";
        for(int i = ans.size()-1; i>= 0; i--){
            
            s += (ans[i] + '0');
        }
        return s;
    }
};

