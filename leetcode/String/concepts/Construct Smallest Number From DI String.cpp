// Construct Smallest Number From DI String

// Example 1:

// Input: pattern = "IIIDIDDD"
// Output: "123549876"
// Explanation:
// At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
// At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
// Some possible values of num are "245639871", "135749862", and "123849765".
// It can be proven that "123549876" is the smallest possible num that meets the conditions.
// Note that "123414321" is not possible because the digit '1' is used more than once.
// Example 2:

// Input: pattern = "DDD"
// Output: "4321"
// Explanation:
// Some possible values of num are "9876", "7321", and "8742".
// It can be proven that "4321" is the smallest possible num that meets the conditions.


class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        stack<int> st;
        string res;

        for(int i = 1; i<= n+1; i++){
            // the value of I is starts with 1 and D is any number because we want to smallest
            // observe the value of I is 1...n/2 and the value of D is n/2...n
            st.push(i);
            char ch = pattern[i-1];

            // if we get n+1 index or if the prev charecter become 'I' then pop all elemenst from stack
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
