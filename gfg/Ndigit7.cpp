// counting n digit numbers with a 7

class Solution {
  public:
  long long binPow(long long a, long long b, long long mod)
  {
      a %= mod;
      long long res = 1;
      while(b > 0)
      {
          if(b%2 == 1  & 1)
          {
              res = res * a % mod;
          }
          a = a* a % mod;
          b >>= 1;
      }
      return res;
  }
    int countWays(int n) {
        long long mod = 1e9 + 7;
      // power is very high so we need to use this function to calculate value.
        long long totalNoCount = (9 * binPow(10, n-1, mod) % mod);
        long long noSevenCount = (8 * binPow(9, n-1, mod) % mod);
        return (totalNoCount - noSevenCount + mod)%mod;
    }
};
