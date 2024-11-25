#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // int maximumSubarrayMul(vector<int> arr){
    //     int n = arr.size();
    //     int maxVal = INT_MIN;
    //     for(int i = 0; i< n; i++){
    //         for(int j = i; j < n; j++){
    //             int mul = 1;
    //             for(int k = i; k <= j; k++){
    //                 mul *= arr[k];
    //             }
    //             maxVal = max(maxVal, mul);
    //         }
    //     }
    //     return maxVal;
    // }
    // this is the brute force solution

    // int maximumSubarrayMul(vector<int> arr)
    // {
    //     int n = arr.size();
    //     int maxVal = INT_MIN;
    //     for (int i = 0; i < n; i++)
    //     {
    //         int mul = 1;
    //         for (int j = i; j < n; j++)
    //         {
    //             mul *= arr[j];
    //             maxVal = max(maxVal, mul);
    //         }
    //     }
    //     return maxVal;
    // }

    int maximumSubarrayMul(vector<int> arr)
    {
        int n = arr.size();
        int maxVal = INT_MIN;
        int per = 1, suff = 1;
        for(int i = 0; i< n; i++){
            if(per == 0) per = 1;
            if(suff == 0) suff = 1;

            per *= arr[i];
            suff *= arr[n-1-i];
            maxVal = max(maxVal , max(per, suff));
        }
        return maxVal;
    }
    // this is the optimal solution
    // 1. if it contain even no -ve element
    // 2. if it contain odd no -ve element
    // 3. if it contain 0
    // we have to calculate multipliction from the start and from the back also. because the maximum sub array is either suffix or perfix position
};

int main()
{
    Solution s;
    vector<int> arr = {-2, 6, -3, -10, 0, 2};
    // vector<int> arr = {-1, -3, -10, 0, 6};
    // vector<int> arr = {2, 3, 4};
    int a = s.maximumSubarrayMul(arr);
    cout << "the answer is " << a;
    return 0;
}
