// Number of 1 Bits.cpp
// Given a positive integer n, write a function that returns the number of 
// set bits
 // in its binary representation (also known as the Hamming weight).


// Example 1:

// Input: n = 11

// Output: 3

// Explanation:

// The input binary string 1011 has a total of three set bits.

// Example 2:

// Input: n = 128

// Output: 1

// Explanation:

// The input binary string 10000000 has a total of one set bit.

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n){
            n = n & (n-1);
            count++;
        }
        return count;
    }
};



// *******************GFG Problem************************
// Longest Consecutive 1's
// Input: N = 14
// Output: 3
// Explanation: 
// Binary representation of 14 is 
// 1110, in which 111 is the longest 
// consecutive set bits of length is 3.


// Input: N = 222
// Output: 4
// Explanation: 
// Binary representation of 222 is 
// 11011110, in which 1111 is the 
// longest consecutive set bits of length 4. 

class Solution
{
    public:
    int maxConsecutiveOnes(int N)
    {
        int maxVal = 0, count = 0;
        while(N){
            int bit = N & 1;
            if(bit == 1){
                count++;
                maxVal = max(maxVal, count);
            }
            else{
                count = 0;
            }
            N = N>>1;
        }
        return maxVal;
    }
};
