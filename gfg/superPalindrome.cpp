#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool is_palindrom(int num)
    {
        string s = to_string(num);
        return s == string(rbegin(s), rend(s));
    }

    int superPalindrom(int l, int n)
    {
        int count = 0;
        for(int i = sqrt(l); i*i <= n; i++)
        {
            int sqr = i*i;
            if(is_palindrom(sqr) && sqr >= l)
                count++;
        }
        return count;
    }
};

int main()
{
    Solution s;
    int ans = s.superPalindrom(1, 100);
    cout<< "total number of super palindrom is "<< ans;
    return 0;
}

