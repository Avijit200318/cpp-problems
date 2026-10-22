// Maximum Without 3 Consecutive Set Bits

// Given a non-negative integer n, you can only change a set bit (1) to an unset bit (0). Find the maximum possible value of n such that its binary representation does not contain three consecutive set bits (111) after performing zero or more allowed operations.

// Examples:

// Input: n = 2
// Output: 2
// Explanation: The binary representation of 2 is 10, which does not contain three consecutive set bits. Therefore, no change is required.


class Solution {
  public:
    int maxValue(int n) {
        // code here
        int count = 0;
        
        for(int i = 29; i>= 0; i--){
            if(n & (1 << i)){
                count++;
                if(count == 3){
                    n &= ~(1 << i);
                    count = 0;
                }
            }
            else{
                count = 0;
            }
        }
        return n;
    }
};