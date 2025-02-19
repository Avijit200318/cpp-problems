// The k-th Lexicographical String of All Happy Strings of Length n

// A happy string is a string that:

// consists only of letters of the set ['a', 'b', 'c'].
// s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
// For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

// Example 1:

// Input: n = 1, k = 3
// Output: "c"
// Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".
// Example 2:

// Input: n = 1, k = 4
// Output: ""
// Explanation: There are only 3 happy strings of length 1.
// Example 3:

// Input: n = 3, k = 9
// Output: "cab"
// Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"
 

class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> res;
        queue<string> q;

        q.push("a");
        q.push("b");
        q.push("c");

        while(!q.empty()){
            string temp = q.front();
            q.pop();

            if(temp.size() == n){
                res.push_back(temp);
                continue;
            }

            if(res.size() >= k) break;

            string first = temp;
            string second = temp;

            if(temp.back() == 'a'){
                first.push_back('b');
                second.push_back('c');
            }
            else if(temp.back() == 'b'){
                first.push_back('a');
                second.push_back('c');
            }
            else{
                first.push_back('a');
                second.push_back('b');
            }


            q.push(first);
            q.push(second);
        }
        if(res.size() < k){
            return "";
        }
        return res[k-1];
    }
};
