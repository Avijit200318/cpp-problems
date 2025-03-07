// 3174. Clear Digits
// Solved
// Easy
// Topics
// Companies
// Hint
// You are given a string s.

// Your task is to remove all digits by doing this operation repeatedly:

// Delete the first digit and the closest non-digit character to its left.
// Return the resulting string after removing all digits.

 

// Example 1:

// Input: s = "abc"

// Output: "abc"

// Explanation:

// There is no digit in the string.

// Example 2:

// Input: s = "cb34"

// Output: ""

class Solution {
public:
    string clearDigits(string s) {
        string res;
        for(auto it : s){
            if(it >= '0' && it <= '9'){
                res.pop_back();
            }
            else{
                res.push_back(it);
            }
        }
        return res;
    }
};
