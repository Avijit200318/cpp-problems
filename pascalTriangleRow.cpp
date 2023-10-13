// brute force method we can use the formul ncr
// in the better we can use the for loop whose go up to c times whose time complexity is o(n*c) [c = column no]

// the bellow code is optimal solution of the problem
// observation -> in nth row we have nth no of elements.

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> printRowOfPascalTriangle(int r)
    {
        int row = r;
        int ans = 1;
        vector<int> arr;
        arr.push_back(1);
        for(int i = 1; i< row; i++)
        {
            ans = ans*(row - i);
            ans = ans/i;
            arr.push_back(ans);
        }
        return arr;
    }
};
// this is the optimal solution whose time complexity is o(r).[r = no of rows] and space complexity is o(r).

int main()
{
    int r = 6;
    Solution s;
    vector<int> a = s.printRowOfPascalTriangle(r);
    for(auto it : a)
    {
        cout<< it<< " ";
    }
    return 0;
}