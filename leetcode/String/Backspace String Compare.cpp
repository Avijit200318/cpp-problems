// Backspace String Compare
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        int n = s.size();
        int m = t.size();

        for(int i = 0; i< n; i++){
            if(!st.empty() && s[i] == '#'){
                st.pop();
            }
            else if(s[i] != '#'){
                st.push(s[i]);
            }
        }

        string res1 = "";

        while(!st.empty()){
            res1 += st.top();
            st.pop();
        }

        for(int i = 0; i< m; i++){
            if(!st.empty() && t[i] == '#'){
                st.pop();
            }
            else if(t[i] != '#'){
                st.push(t[i]);
            }
        }

        string res2 = "";

        while(!st.empty()){
            res2 += st.top();
            st.pop();
        }

        return res1 == res2;
    }
};
