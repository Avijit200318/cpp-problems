// Construct Smallest Number From DI String -> leetcode


// Example 1:

// Input: pattern = "IIIDIDDD"
// Output: "123549876"
// Explanation:
// At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
// At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
// Some possible values of num are "245639871", "135749862", and "123849765".
// It can be proven that "123549876" is the smallest possible num that meets the conditions.
// Note that "123414321" is not possible because the digit '1' is used more than once.


#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string smallestNumber(string s){
        int n = s.size();
        stack<int> st;
        string res;

        for(int i = 1; i<= n+1; i++){
            // the loop travarse from 1 to 9 for maximum case. but the size of the string s is maximum 8 means the last value is 7.
            st.push(i);
            char ch = s[i-1];
            // so the last value of ch is a null value or garbage value

            // we are chacking if charecter is 'I' or i become the last value where c is a garbage value. If yes then empty stack
            if(i == n+1 || ch == 'I'){
                while(!st.empty()){
                    res.push_back('0' + st.top());
                    st.pop();
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    string a = s.smallestNumber("IIIDIDDD");
    // string a = s.smallestNumber("DDD");
    cout<<"The answer is : "<<a;
    return 0;
}
