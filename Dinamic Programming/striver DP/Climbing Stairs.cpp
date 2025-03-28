// Climbing Stairs

// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

#include<bits/stdc++.h>
using namespace std;


// normal recursion solution
// int climbStairs(int n) {
//     if(n == 0) return 1;
//     if(n == 1) return 1;

//     we need to count each case
//     int left =  climbStairs(n-1);
//     int right =  climbStairs(n-2);
//     return left + right;
// }


// this problem is almost similar to fibonacii problem
// so I solve it to most optimal way
int climbStairs(int n) {
    if(n == 0) return 1;
    if(n == 1) return 1;
    // this base case occur because of the case when n = 1 and we are substarcting by 2 means the overall index become -1

    int cur;
    int prev = 1, prev2 = 1;
    for(int i = 2; i<= n; i++){
        cur = prev + prev2;
        prev2 = prev;
        prev = cur;
    }

    return cur;
}

int main(){
    int n = 6;

    int a = fibonacii(n);
    cout<<"the answer is: "<<a;
    return 0;
}
