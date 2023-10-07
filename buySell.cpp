#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int buySell(vector <int> arr)
    {
        int minBuy = arr[0], profit = 0;
        for(int i = 1; i< arr.size(); i++)
        {
            int cost = arr[i] - minBuy;
            profit = max(profit, cost);
            minBuy = min(minBuy, arr[i]);
        }
        return profit;
    }
};

int main()
{
    vector <int> v = {7, 1, 5, 3, 6 , 4};
    Solution s;
    int a = s.buySell(v);
    cout << a;
    return 0;
}