// just print all the tiles of stirng combination

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void buildAllCombination(vector<int> &feq, string s, vector<string> &ans) {
        // Store the current combination if it's not empty
        if (!s.empty()) {
            ans.push_back(s);
        }

        for (int i = 0; i < 26; i++) {
            if (feq[i] > 0) {
                feq[i]--;  // Use one occurrence of this letter
                buildAllCombination(feq, s + char('A' + i), ans);
                feq[i]++;  // Backtrack to restore state
            }
        }
    }

    vector<string> letterTilesPossible(string s) {
        vector<int> feq(26, 0);
        vector<string> ans;

        // Count frequency of each character
        for (char c : s) {
            feq[c - 'A']++;
        }

        // Start recursive function with an empty string
        buildAllCombination(feq, "", ans);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> result = sol.letterTilesPossible("AAB");

    cout << "The answer is: " << result.size() << endl;
    for (const string &str : result) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}
