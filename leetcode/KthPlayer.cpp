// 3175. Find The First Player to win K Games in a Row

// A competition consists of n players numbered from 0 to n - 1.

// You are given an integer array skills of size n and a positive integer k, where skills[i] is the skill level of player i. All integers in skills are unique.

// All players are standing in a queue in order from player 0 to player n - 1.

// The competition process is as follows:

// The first two players in the queue play a game, and the player with the higher skill level wins.
// After the game, the winner stays at the beginning of the queue, and the loser goes to the end of it.
// The winner of the competition is the first player who wins k games in a row.

// Return the initial index of the winning player.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int size = skills.size();
        if (k >= size) {
        // If k is greater than or equal to n, the player with the highest skill wins
        return max_element(skills.begin(), skills.end()) - skills.begin();
        }
        queue<int> arr;
        for(int i = 0; i< size; i++){
            arr.push(i);
        };
        int current_winner = arr.front();
        arr.pop();
        int win = 0;
        
        while(win < k)
        {
            int challenger = arr.front();
            arr.pop();
            if(skills[current_winner] > skills[challenger])
            {
                win++;
                arr.push(challenger);
            }
            else{
                win = 1;
                arr.push(current_winner);
                current_winner = challenger;
            }
        }
        return current_winner;
    }
};
