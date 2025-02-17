class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream s1(s), s2(s);
        map<char, string> mpp;
        map<string, char> revMpp;
        vector<string> words;
        string word;
        
        while (s2 >> word) {  // Extract words. to extract the words first you need to create stringstream (s2) and a empty string variable(word)
        words.push_back(word);
        }
        if(words.size() != pattern.size()) return false;

        // the bellow iterations I did using getline but you just need to use the words vector to perform the same thing. I just use getline to know more about this funciton in cpp. And if the string s is shorter than pattern then geline -> return "" when the string index is overflow
        int size = 0;
        string str;
        for(int i = 0; i< pattern.size(); i++){
            size++;
            getline(s1, str, ' ');
            if(mpp.find(pattern[i]) != mpp.end()){
                if(mpp[pattern[i]] != str) return false;
            }
            mpp[pattern[i]] = str;
            if(revMpp.find(str) != revMpp.end()){
                if(revMpp[str] != pattern[i]) return false;
            }
            revMpp[str] = pattern[i];
        } 
        return true;
    }
};
