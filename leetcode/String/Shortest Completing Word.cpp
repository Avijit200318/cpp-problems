// Shortest Completing Word
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> hash(26, 0);
        // created a hash table

        for(auto it : licensePlate){
            // isalpha is check if it is an alphabet or not. or we can write it >= 'a' and it <= 'z' or it >= 'A' and it <= 'Z'
            if(isalpha(it)){
                hash[tolower(it) - 'a']++;
                // increase the hash index
            }
        }

        string ans = "";
        int minLen = INT_MAX, n = words.size();

        for(int i = 0; i< n; i++){
            if(minLen <= words[i].size()) continue;
            // this line help us situation like where we already has an answer and we go to check some string wich is greater length than the answer.

            vector<int> temp(hash.begin(), hash.end());
            // copy the hash value into temp so that we have a copy for conditional check

            for(int j = 0; j< words[i].size(); j++){
                temp[tolower(words[i][j]) - 'a']--;
            }

            int j = 0;
            // if temp[j] any value is greater than 0 means it still have some charecter that the string should have. then break it
            for(j = 0; j< 26; j++){
                if(temp[j] > 0) break;
            }

            // if all the temp value is <= 0 means this is our answer
            if(j == 26){
                minLen = words[i].size();
                ans = words[i];
            }
        }
        return ans;
    }
};
