// Maximum Points You Can Obtain from Cards

// There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

// Your score is the sum of the points of the cards you have taken.

// Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

 

// Example 1:

// Input: cardPoints = [1,2,3,4,5,6,1], k = 3
// Output: 12
// Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
// Example 2:

// Input: cardPoints = [2,2,2], k = 2
// Output: 4
// Explanation: Regardless of which two cards you take, your score will always be 4.
// Example 3:

// Input: cardPoints = [9,7,7,9,7,7,9], k = 7
// Output: 55
// Explanation: You have to take all the cards. Your score is the sum of points of all cards.

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // we need to max the sum of k elements
        // so we can think it like we can calculate total - min sum of n-k elements
        // which will give us max sum of k elements

        int n = cardPoints.size();
        int left = 0;
        int sum = 0, totalSum = 0;
        int minVal = INT_MAX;

        for(int right = 0; right < n; right++){
            sum += cardPoints[right];
            totalSum += cardPoints[right];

            while(right - left + 1 == n-k){
                minVal = min(minVal, sum);
                sum -= cardPoints[left];
                left++;
            }
        }
        // if it k == n then the minVal will not update. then return totalSum
        if(minVal == INT_MAX){
            return totalSum;
        }
        return totalSum - minVal;   
    }
};



// we can use dynamic programing here but it will give us TLE
class Solution {
public:
    int solve(int k, int left, int right, vector<int> &arr, map<pair<int, int>, int> &memo){
        if(k == 0) return 0;
        pair<int, int> key = {left, right};
        
        if(memo.find(key) != memo.end()) return memo[key];

        int firstPick = arr[left] + solve(k-1, left+1, right, arr, memo);

        int lastPick = arr[right] + solve(k-1, left, right-1, arr, memo);

        memo[key] = max(firstPick, lastPick);
        return max(firstPick, lastPick);
    }

    int maxScore(vector<int>& cardPoints, int k) {
        int maxSum = 0;
        int n = cardPoints.size();
        map<pair<int, int>, int> memo;
        return solve(k, 0, n-1, cardPoints, memo);
    }
};