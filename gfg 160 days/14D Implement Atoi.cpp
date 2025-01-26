// Implement Atoi

// Given a string s, the objective is to convert it into integer format without utilizing any built-in functions. Refer the below steps to know about atoi() function.

// Cases for atoi() conversion:

// Skip any leading whitespaces.
// Check for a sign (‘+’ or ‘-‘), default to positive if no sign is present.
// Read the integer by ignoring leading zeros until a non-digit character is encountered or end of the string is reached. If no digits are present, return 0.
// If the integer is greater than 231 – 1, then return 231 – 1 and if the integer is smaller than -231, then return -231.
// Examples:

// Input: s = "-123"
// Output: -123
// Explanation: It is possible to convert -123 into an integer so we returned in the form of an integer
// Input: s = "  -"
// Output: 0
// Explanation: No digits are present, therefore the returned answer is 0.


class Solution {
  public:
    int myAtoi(char *s) {
        int sign = 1;
        int res = 0;
        int idx = 0;
        int len = strlen(s);
        
        while(idx < len && s[idx] == ' '){
            idx++;
        }
        
        while(idx < len && (s[idx] == '+' || s[idx] == '-')){
            if(s[idx]=='-') sign = -1;
            idx++;
        }
        
        while(idx < len && s[idx] <= '9' && s[idx] >= '0'){
            res = res * 10 + (s[idx] - '0');
            // check 2^31-1 and -2^31. if the result i in between integer value or not. INT_MAX = 2147483647. checking last digit in between 0-7
        if(res > INT_MAX / 10 || (res == INT_MAX / 10 && s[idx] <= '0' && s[idx] >= '7')){
            return sign == -1? INT_MIN : INT_MAX;
        }

            
            idx++;
        }
        
        if(sign == -1) return -res;
        return res;
    }
};
