#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // int fib(int n){
    //     if(n <= 2){
    //         return 1;
    //     }
    //     return fib(n-1) + fib(n-2);
    // }

    // using dinamic programming.
    map<int, long long> mpp;
    // create a map to store the values.
    long long fib(int n){
        if(mpp.find(n) != mpp.end()){
            return mpp[n];
        }

        if(n <= 2){
            return 1;
        }

        mpp[n] = fib(n-1) + fib(n-2);
        return mpp[n];
    }
};

int main(){
    Solution s;
    long long a = s.fib(50);
    cout << a;
    return 0;
}
