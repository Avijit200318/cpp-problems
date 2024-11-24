// buy and sell II (buy and sell multiple times)
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // better solution

    // int multipleBuyAndSell(vector<int> arr){
    //     int n = arr.size();
    //     int lMin = 0, lMax = 0;
    //     int i = 0;
    //     int res = 0;
    //     while(i < n-1){
    //         while(i < n-1 && arr[i] >= arr[i+1]){
    //             i++;
    //         }

    //         lMin = arr[i];

    //         while(i < n-1 && arr[i] <= arr[i+1]){
    //             i++;
    //         }
    //         lMax = arr[i];

    //         res += (lMax - lMin);
    //     }
    //     return res;
    // }

    // optimal solution

    int multipleBuyAndSell(vector<int> arr){
        int n = arr.size();
        int res = 0;
        for(int i = 1; i< n; i++){
            if(arr[i] > arr[i-1]){
                res += arr[i] - arr[i-1];
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> arr = {100, 180, 260, 310, 40, 535, 695};
    int a = s.multipleBuyAndSell(arr);
    cout<< "the answer is "<< a;
    return 0;
}
