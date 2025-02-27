// Best Time to Buy and Sell Stock II -> leetcode / GFG

// here instead of buy one times the user can buy any number of times and sell it any number of times. and we need to calculate the maximum profite of the user.


// so we just need to check if arr[i] is greater than its previous element. if Yes means he buy it to i-1 day and sell it to next day
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for(int i = 1; i< prices.size(); i++){
            if(prices[i] > prices[i-1]){
                res += prices[i] - prices[i-1];
            }
        }
        return res;
    }
};
