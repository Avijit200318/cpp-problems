// Min Chars to Add for Palindrome
// Difficulty: HardAccuracy: 46.79%Submissions: 79K+Points: 8Average Time: 25m
// Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.

// Note: A palindrome string is a sequence of characters that reads the same forward and backward.

// Examples:

// Input: s = "abc"
// Output: 2
// Explanation: Add 'b' and 'c' at front of above string to make it palindrome : "cbabc"

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool checkPalindrom(string s, int i, int j){
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    // int minCharToAddToMakePalindrom(string s){
    //     int n = s.size();

    //     int count = 0;
    //     for(int i= n-1; i>= 0; i--){
    //         if(checkPalindrom(s, 0, i)){
    //             return count;
    //         }
    //         else{
    //             count++;
    //         }
    //     }
    //     return count;
    // }
    // it takes o(n^2) timecomplexity


// we just need to create the lps for stirng + $ + rev string and the least lps value tell us how much of the sting is plaindrom
    vector<int> createLps(string pat){
        int n = pat.size();
        vector<int> lps;
        lps.push_back(0);

        int len = 0, i = 1;
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
                    i++;
                    lps.push_back(0);
                }
            }
        }
        return lps;
    }

    int minCharToAddToMakePalindrom(string s){
        int n = s.size();

        string rev = s;
        reverse(rev.begin(), rev.end());
        string s1 = s + '$' + rev;
        cout<<s1<<endl;
        vector<int> lps = createLps(s1);
        for(int i = 0; i< lps.size(); i++){
            cout<<lps[i]<<" ";
        }
        cout<<endl;
        return n - lps[lps.size()-1];
    }
};

int main(){
    Solution s;
    int a = s.minCharToAddToMakePalindrom("aacecaaaa");
    // int a = s.minCharToAddToMakePalindrom("aacecaa");
    // int a = s.minCharToAddToMakePalindrom("abc");
    cout<<"The answer is : "<<a;
    return 0;
}
