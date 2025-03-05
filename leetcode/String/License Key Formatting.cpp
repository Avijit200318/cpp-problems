// // License Key Formatting

// Example 1:

// Input: s = "5F3Z-2e-9-w", k = 4
// Output: "5F3Z-2E9W"
// Explanation: The string s has been split into two parts, each part has 4 characters.
// Note that the two extra dashes are not needed and can be removed.
// Example 2:

// Input: s = "2-5g-3-J", k = 2
// Output: "2-5G-3J"
// Explanation: The string s has been split into three parts, each part has 2 characters except the first part as it could be shorter as mentioned above.


class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        stack<string> st;
        int n = s.size();
        string s1 = "";

        for(int i = n-1; i>= 0; i--){
            if(s[i] != '-'){
                if(s[i] >= 'a' && s[i] <= 'z'){
                    s1 = char(s[i]-32) + s1;
                }
                else{
                s1 = s[i] + s1;
                }

                if(s1.size() == k){
                    st.push(s1);
                    s1 = "";
                }
            }
        }

        if(s1.size() != 0){
            st.push(s1);
            s1 = "";
        }

        if(s1.size() == 0 && st.empty()) return "";

        while(!st.empty()){
            s1 += st.top() + "-";
            st.pop();
        }
        s1.pop_back();
        return s1;
    }
};
