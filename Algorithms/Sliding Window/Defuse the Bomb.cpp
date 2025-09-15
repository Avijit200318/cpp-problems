// 5. Defuse the Bomb
// You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular array code of length of n and a key k.

// To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.

// If k > 0, replace the ith number with the sum of the next k numbers.
// If k < 0, replace the ith number with the sum of the previous k numbers.
// If k == 0, replace the ith number with 0.
// As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].

// Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!

// Example 1:

// Input: code = [5,7,1,4], k = 3
// Output: [12,10,16,13]
// Explanation: Each number is replaced by the sum of the next 3 numbers. The decrypted code is [7+1+4, 1+4+5, 4+5+7, 5+7+1]. Notice that the numbers wrap around.

// class Solution {
// public:
//     vector<int> decrypt(vector<int>& code, int k) {
//         int n = code.size();
//         vector<int> ans(n, 0);

//         if(k == 0) return ans;

//         for(int i = 0; i< n; i++){
//             if(k > 0){
//                 for(int j = i+1; j< i+1+k; j++){
//                     ans[i] += code[j % n];
//                 }
//             }
//             else{
//                 for(int j = i-1; j> i-1-abs(k); j--){
//                     if(j < 0){
//                         ans[i] += code[(n+j) % n];
//                     }
//                     else{
//                         ans[i] += code[j%n];
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };
// o(n * k) time complexity


// if our index become -ve then we can just add n. to make it non negative
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        int sum = 0, start = 0;

        if(k == 0) return ans;

        for(int i = 0; i< n+abs(k); i++){
            sum += code[i % n];

            if(i - start + 1 > abs(k)){
                sum -= code[start % n];
                start = (start + 1) % n;
            }

            if(i - start + 1 == abs(k)){
                if(k > 0){
                    // if our index become -ve then we can just add n. to make it non negative. need when start become n and n % n == 0 start become 0 and we want to get start - 1= -1 index
                    ans[(start-1 + n) % n] = sum;
                }
                else{
                    ans[(i+1) % n] = sum;
                }
            }
        }
        return ans;
    }
};
// this will o(n+k) time