// Number of Lines To Write StringYou are given a string s of lowercase English letters and an array widths denoting how many pixels wide each lowercase English letter is. Specifically, widths[0] is the width of 'a', widths[1] is the width of 'b', and so on

// Example 1:

// Input: widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10], s = "abcdefghijklmnopqrstuvwxyz"
// Output: [3,60]
// Explanation: You can write s as follows:
// abcdefghij  // 100 pixels wide
// klmnopqrst  // 100 pixels wide
// uvwxyz      // 60 pixels wide
// There are a total of 3 lines, and the last line is 60 pixels wide.
// Example 2:

// Input: widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10], s = "bbbcccdddaaa"
// Output: [2,4]
// Explanation: You can write s as follows:
// bbbcccdddaa  // 98 pixels wide
// a            // 4 pixels wide
// There are a total of 2 lines, and the last line is 4 pixels wide.


class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int n = s.size();

        int sum = 0;
        int count = 0;

        for(int i = 0; i< n; i++){
            if(count == 0) count = 1;
            sum += widths[s[i] - 'a'];
            
            if(sum > 100){
                sum = widths[s[i] - 'a'];
                count++;
            }
        }

        return {count, sum};
    }
};
