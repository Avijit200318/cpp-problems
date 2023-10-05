#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int nameToColumnNumber(string s)
    {
        int res = 0;
        int n = s.length();
        for(int i = 0; i< n; i++)
        {
            res = res * 26 + int(s[i]) - 64;
        }
        return res;
    }
};

int main()
{
    Solution s;
    // int a = s.nameToColumnNumber("AB");;
    int a = s.nameToColumnNumber("AF");
    cout<< a;
    // Ab = 28, 
    return 0;
}