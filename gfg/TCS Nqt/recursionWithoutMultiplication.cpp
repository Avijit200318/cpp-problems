// recursion without multiplication

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int factorialWithoutMul(int n){
        cout<<"running";
        int ans = n;
        for(int i = n-1; i> 0; i--)
        {
            int sum = 0;
            for(int j = 0; j< i; j++){
                sum += ans;
            }
            cout<< sum<<endl;
        ans = sum;
        }
        return ans;
    }
};

int main(){
    Solution s;
    int a = s.factorialWithoutMul(5);
    cout<< a;
    return  0;
}
