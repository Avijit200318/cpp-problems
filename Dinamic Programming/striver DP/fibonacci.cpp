#include<bits/stdc++.h>
using namespace std;

int fibonacii(int n, vector<int> &memo){
    if(n <= 1){
        return n;
    }

    if(memo[n] != -1) return memo[n];

    memo[n] = fibonacii(n-1, memo) + fibonacii(n-2, memo);
    return memo[n];
}

int main(){
    int n = 5;
    vector<int> memo(n+1, -1);
    
    int a = fibonacii(n, memo);
    cout<<"the answer is: "<<a;
    return 0;
}

// time = o(n) and space = o(n) + recustion stack space


// ****tabular method******
#include<bits/stdc++.h>
using namespace std;

int fibonacii(int n){
    vector<int> table(n+1, 0);
    table[0] = 0;
    table[1] = 1;
    // add alll the base cases

    // after the base cases we are sure that we will start from i = 2.
    for(int i = 2; i<= n; i++){
        table[i] = table[i-1] + table[i-2];
    }
    return table[n];
}

int main(){
    int n = 5;

    int a = fibonacii(n);
    cout<<"the answer is: "<<a;
    return 0;
}

// tc = o(n) and space = o(n) no recursion asculary space

// *****more optimal solution*********
#include<bits/stdc++.h>
using namespace std;

int fibonacii(int n){
    if(n <= 1){
        return n;
    }

    int prev2 = 0, prev = 1;
    int curr;
    
    for(int i = 2; i<= n; i++){
        curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }

    return curr;
}

int main(){
    int n = 6;

    int a = fibonacii(n);
    cout<<"the answer is: "<<a;
    return 0;
}

// tc = o(n) but sc = o(1)
