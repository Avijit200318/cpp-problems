// // Valid Palindrome II
// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

// Example 1:

// Input: s = "aba"
// Output: true
// Example 2:

// Input: s = "abca"
// Output: true
// Explanation: You could delete the character 'c'.
// Example 3:

// Input: s = "abc"
// Output: false

class Solution {
public:
    bool isPalindrom(string s, int left, int right){
        int n = s.size();

        while(left < right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n-1;

        // we can delete one element from the string. so we will traverse left and right if they are not equal then check if we delete from left then is it true? or if we delete from right then it is true?
        while(left < right){
            if(s[left] != s[right]){
                return isPalindrom(s, left + 1, right) || isPalindrom(s, left, right-1);
                // if both of them are false then it retrun false. and if one of them true then it return true. means if the string is palindrom it will take time complexity like o(n) and if it not because of some charecter then it will check palindrom condition and it also take o(n).
            }
            left++;
            right--;
        }
        return true;
    }
};
