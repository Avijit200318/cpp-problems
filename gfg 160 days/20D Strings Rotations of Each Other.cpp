// Strings Rotations of Each Other
// Difficulty: EasyAccuracy: 43.83%Submissions: 244K+Points: 2Average Time: 15m
// You are given two strings of equal lengths, s1 and s2. The task is to check if s2 is a rotated version of the string s1.

// Note: The characters in the strings are in lowercase.

// Examples :

// Input: s1 = "abcd", s2 = "cdab"
// Output: true
// Explanation: After 2 right rotations, s1 will become equal to s2.

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // int stringRotationCheck(string a, string b){
    //     int n = a.size();
    //     int m = b.size();
    //     if(n != m) return 0;

    //     for(int i = 0; i< n; i++){
    //         reverse(a.begin(), a.begin()+i);
    //         reverse(a.begin()+1, a.end());
    //         reverse(a.begin(), a.end());

    //         if(a == b) return 1;
    //     }
    //     return 0;
    // }
    // time complexity is o(n^2)


// using KMP algorightm
    vector<int> createLps(string pat){
        vector<int> lpsList;
        lpsList.push_back(0);

        int len = 0, n = pat.size(), i = 1;
        while(i < n){
            if(pat[len] == pat[i]){
                len++;
                lpsList.push_back(len);
                i++;
            }
            else{
                if(len != 0){
                    len = lpsList[len - 1];
                }
                else{
                    lpsList.push_back(0);
                    i++;
                }
            }
        }
        return lpsList;
    }

    int stringRotationCheck(string a, string b){
        int n = a.size();
        int m = b.size();
        if(n != m) return 0;

        string s = a + a;
        vector<int> lps = createLps(b);
        int i = 0, j = 0;

        while(i < s.size()){
            if(s[i] == b[j]){
                i++;
                j++;

                if(j == m){
                    return 1;
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
        return 0;
    }
};

int main(){
    Solution s;
    int a = s.stringRotationCheck("abcd", "cdab");
    // int a = s.stringRotationCheck("aab", "aba");
    // int a = s.stringRotationCheck("abcd", "acbd");
    cout<< "the answer is: "<<a;
    return 0;
}
