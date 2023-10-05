#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int romanToNumber(string s)
    {
        map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},{'C', 100}, {'D', 500}, {'M', 1000}};
        int res = 0, preValue = 0;
        int n = s.length();
        for(int i = n-1; i >=0; i--)
        {
            int value = m[s[i]];
            if(value < preValue)
            {
                res -= value;
            }
            else
            {
                res += value;
            }
            preValue= value;
        }
        return res;
    }
};


int main()
{
    Solution s;
    // int a = s.romanToNumber("IV");
    int a = s.romanToNumber("IX");
    cout<< a;
}