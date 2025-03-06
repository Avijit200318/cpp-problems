// Count Binary Substrings
// Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

// Substrings that occur multiple times are counted the number of times they occur.

 

// Example 1:

// Input: s = "00110011"
// Output: 6
// Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
// Notice that some of these substrings repeat and are counted the number of times they occur.
// Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
// Example 2:

// Input: s = "10101"
// Output: 4
// Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.


class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int prev = 0, curr = 1;
        int count = 0;

        // we need to find the group elements like 000 or 111
        // for example 0011 the count will be 2 because we can create 01, 0011
        // 00111 -> 01, 0011 output: 2 -> we need to check min(no of ones, no of 0s)

        // start a curr = 1, prev = 0
        // start traversing from 1 if the previous element is same then incrase curr
        // if not then we find some pair which are together. add them to sum += min()
        // set prev = curr and set cur = 1. -> if string starts from 0 curr count no of 0s then when we get a 1 then the prev will store the no of 0s value and the curr will reset to 1 to count the next set of consicutive 1's


        for(int i = 1; i< n; i++){
            if(s[i] != s[i-1]){
                count += min(prev, curr);
                prev = curr;
                curr = 1;
            }
            else{
                curr++;
            }
        }
        count += min(prev, curr);
        return count;
    }
};
