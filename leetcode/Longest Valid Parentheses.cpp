// Longest Valid Parentheses

// Example 1:

// Input: s = "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()".
// Example 2:

// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".
// Example 3:

// Input: s = ""
// Output: 0

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int index = -1, maxVal = 0;
        int n = s.size();

        for(int i = 0; i< n; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                if(!st.empty()){
                    st.pop();

                    if(!st.empty()){
                        maxVal = max(maxVal, i - st.top());
                    }
                    else{
                        maxVal = max(maxVal, i - index);
                    }
                }
                else{
                    index = i;
                }
            }
        }
        return maxVal;
    }
};
