// given a number 28 convert it to its column number
// A = 1, z = 26, AA = 27, AB = 28 ...etc.  

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string ColumnNameToNumber(int n)
    {
        string res = "";
        while( n > 0)
        {
            int rem = (n-1) % 26;
            res = char(65 + rem) + res;
            n = (n-1)/26;
        }
        return res;
    }
};

int main()
{
    // 28 = AB, A = 65, 28%26 = 2
    Solution s;
    // string a = s.ColumnNameToNumber(28);
    string a = s.ColumnNameToNumber(32);
    cout<< a;
    return 0;
}