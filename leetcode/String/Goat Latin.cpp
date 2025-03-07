// Goat Latin
// If a word begins with a vowel ('a', 'e', 'i', 'o', or 'u'), append "ma" to the end of the word.
// For example, the word "apple" becomes "applema".
// If a word begins with a consonant (i.e., not a vowel), remove the first letter and append it to the end, then add "ma".
// For example, the word "goat" becomes "oatgma".
// Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
// For example, the first word gets "a" added to the end, the second word gets "aa" added to the end, and so on.
// Return the final sentence representing the conversion from sentence to Goat Latin.

 

// Example 1:

// Input: sentence = "I speak Goat Latin"
// Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
// Example 2:

// Input: sentence = "The quick brown fox jumped over the lazy dog"
// Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"


class Solution {
public:
    string helper(string s, int idx){
        int n = s.size();
        string res = "";
        if(tolower(s[0]) != 'a' && tolower(s[0]) != 'e' && tolower(s[0]) != 'i' && tolower(s[0]) != 'o' && tolower(s[0]) != 'u'){
            res= s.substr(1, n);
            res +=s[0];
        }
        else{
            res = s;
        }
        res += "ma";
        int i = 0;

        while(i < idx){
            res += 'a';
            i++;
        }

        return res;
    }
    string toGoatLatin(string sentence) {
        int n = sentence.size();
        string ans = "";

        stringstream ss(sentence);
        string s1;
        int idx = 1;

        while(ss >> s1){
            string temp = helper(s1, idx);
            idx++;
            ans += temp + ' ';
        }
        
        if(ans.size() != 0){
        ans.pop_back();
        }
        return ans;
    }
};
