// e2 = gee and e1 = ge
class Solution {
  public:
    int geekCount(string s) {
        int mod = 1e9+7;
        int g = 0;
        int e1 = 0;
        int e2 = 0;
        int ans = 0;
        for(int i = 0; i< s.size(); i++)
        {
            if(s[i] == 'g')
            {
                g++;
            }
            else if(s[i] == 'e')
            {
                e2 = (e2 + e1)%mod;
                e1 = (e1 + g)%mod;
            }
            else if(s[i] == 'k')
            {
                ans = (ans + e2)%mod;
                ans = ans % mod;
            }
        }
        return ans;
    }
};
