// unique path or gridTraveler

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // int gridTraveler(int m ,int n){
    //     if(m == 1 && n ==1) return 1;
    //     if(m == 0 || n == 0) return 0;

    //     return gridTraveler(m-1, n) + gridTraveler(m, n-1);
    // }

    // recursion uses timecomplexity of 2^n.

    map<pair<int, int>, long long> mpp;

    long long gridTraveler(int m ,int n){
        if(mpp.find({m, n}) != mpp.end()){
            return mpp[{m, n}];
        }

        if(m == 1 && n ==1) return 1;
        if(m == 0 || n == 0) return 0;

        mpp[{m, n}] = gridTraveler(m-1, n) + gridTraveler(m, n-1);
        return mpp[{m, n}];
    }
};

int main(){
    Solution s;
    // long long a = s.gridTraveler(1,1);
    // long long a = s.gridTraveler(2, 3);
    // long long a = s.gridTraveler(3,2);
    long long a = s.gridTraveler(18, 18);
    cout<< "ans: "<< a;
    return 0;
}
