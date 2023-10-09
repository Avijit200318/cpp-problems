// [17, 18, 5, 4, 6, 1] => ans = [18, 6, 6, 6, 1, -1]
// the last element is 1 so for it -1 because there is no element in the right side.
//for 17 we check 18 to the last element and 18 is the bigger so answer is 18.

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector <int> leaderArray(vector <int> arr)
    {
        int n = arr.size();
        vector <int> res;
        res.push_back(-1);
        res.push_back(arr[n-1]);
        int maxi = arr[n-1];
        for(int i =  n-3; i>= 0; i--)
        {
            maxi = max(maxi, arr[i+1]);
            res.push_back(maxi);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// this is the optimal solution whose time complexity is o(N^2) and space complexity is o(n).

int main()
{
    vector <int> v ={17, 18, 5, 4, 6, 1};
    Solution s;
    vector <int> a = s.leaderArray(v);
    for(auto it : a)
    {
        cout<< it<< " ";
    }
    return 0;
}