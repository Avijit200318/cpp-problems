// write a program to calculate the pairs count in the given array such that the sum of the paris is divisible by 2.
// {2, 2, 1, 5, 7, 3} => output 7

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int factorial(int n){
        int ans = 1;
        for(int i = 1; i<= n; i++){
            ans = ans * i;
        }
        return ans;
    }

    int noOfPair(vector<int> arr){
        int n = arr.size();
        int evenNo = 0, oddNo = 0;
        for(int i = 0; i< n; i++){
            if(arr[i] % 2 == 0){
                evenNo++;
            }
            else{
                oddNo++;
            }
        }
        int evenr = evenNo - 2;
        int oddr = oddNo -2;
        int resEvnR = factorial(evenr);
        int resOddR = factorial(oddr);
        evenNo = (factorial(evenNo)/2)/resEvnR;
        oddNo = (factorial(oddNo)/2)/resOddR;
        return evenNo + oddNo;
    }
};

int main(){
    Solution s;
    // vector<int> arr = {2, 2, 1, 7,5, 3};
    vector<int> arr = {2, 2, 4, 8, 1, 1, 7,5, 3};
    int ans = s.noOfPair(arr);
    cout<< "ans is "<<ans;
    return 0;
}
