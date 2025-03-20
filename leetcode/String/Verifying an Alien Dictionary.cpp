// Verifying an Alien Dictionary

// Example 1:

// Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
// Output: true
// Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
// Example 2:

// Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
// Output: false
// Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> mpp;
        // sotre all the indexs of the order string charters so that we can tell laxigraphically sort or not using the order

        for(int i = 0; i< order.size(); i++)   {
            mpp[order[i]] = i;
        }
        int n = words.size();

        // comparing two string at a time
        for(int i = 0; i< n-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];

            int m = max(s1.size(), s2.size());
            // m is maximum size of the s1 and s2

            // if s1 is smaller then its lexigraphically sorted but if s2 then retuern false

            for(int j = 0; j< m; j++){
                if(j == s2.size()){
                    return false;
                }

                // if the charecters are not equal then check mpp is they are in sorted order or not
                if(s1[j] != s2[j]){
                    if(mpp[s1[j]] > mpp[s2[j]]) return false;
                    break;
                }
            }
        }

        return true;
    }
};
