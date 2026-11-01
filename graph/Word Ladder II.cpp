// Word Ladder II

// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

 

// Example 1:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
// Explanation: There are 2 shortest transformation sequences:
// "hit" -> "hot" -> "dot" -> "dog" -> "cog"
// "hit" -> "hot" -> "lot" -> "log" -> "cog"



class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});

        // to keep track which word we used for transformation
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>> ans;

        while(!q.empty()){
            vector<string> temp = q.front();
            q.pop();

            // erase all the word that has been used in the previous level
            if(temp.size() > level){
                level++;
                for(auto it : usedOnLevel){
                    st.erase(it);
                }
                usedOnLevel.clear();
            }

            string word = temp.back();

            // check if we find the final word
            if(word == endWord){
                if(ans.size() == 0){
                    ans.push_back(temp);
                }
                // if ans has already value and we got another sequence
                else if(ans[0].size() == temp.size()){
                    ans.push_back(temp);
                }
            }

            for(int i = 0; i< word.size(); i++){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        temp.push_back(word);
                        q.push(temp);

                        usedOnLevel.push_back(word);
                        // remove string from the temp becasue we will find all the combination
                        temp.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};


// ****this will work fine in gfg but give use MLE in leetcode***


// ***Leetcode optimize way****
