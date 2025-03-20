// Find Common Characters

// Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

 

// Example 1:

// Input: words = ["bella","label","roller"]
// Output: ["e","l","l"]
// Example 2:

// Input: words = ["cool","lock","cook"]
// Output: ["c","o"]

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        map<char, int> mpp;
        int n = words.size();
        vector<string> ans;

        // count the frequcies of all the charecters in the first string
        for(int  i = 0; i< words[0].size(); i++){
            mpp[words[0][i]]++;
        }

        // traversing each stirng and counting the number of charecters for each string
        for(int i = 0; i< n; i++){
            map<char, int> mpp2;
            for(int j = 0; j< words[i].size(); j++){
                mpp2[words[i][j]]++;
            }

            // we are comparing all the charecters of other stirng or mpp2 to the first string becasue we want the minimum
            for(auto it : words[0]){
                mpp[it] = min(mpp[it], mpp2[it]);
            }
        }


        for(auto it : mpp){
            // if the element is present only 1 times then add it
            if(it.second == 1){
                ans.push_back(string(1, it.first));
            }
            else if(it.second > 1){
                // if the element is present more than one times then loop it and push it into array
                for(int i = 0; i< it.second; i++){
                    ans.push_back(string(1, it.first));
                }
            }
        }

        return ans;
    }
};
