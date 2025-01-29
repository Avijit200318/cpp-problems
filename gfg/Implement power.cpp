// 50. Pow(x, n) -> leetcode / Implement Pow -> GFG

// Solved
// Medium
// Topics
// Companies
// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

// Example 1:

// Input: x = 2.00000, n = 10
// Output: 1024.00000

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n == INT_MIN){
            return 1/(myPow(x, -(n+1)) * x);
        }
        if(n < 0) return 1/myPow(x, -n);
        double halfPow = myPow(x, n/2);
        if(n % 2 == 0){
            return halfPow * halfPow;
        }
        return x*halfPow*halfPow;
    }
};
