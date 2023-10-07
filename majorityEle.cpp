#include<bits/stdc++.h>
using namespace std;

// class Solution
// {
//     public:
//     int majorityElement(vector <int> arr)
//     {
//         int n = arr.size();
//         int count = 0, ele = 0, maxCount = INT_MIN;
//         for(int i = 0; i< n; i++)
//         {
//             count = 0;
//             for(int j = 0; j< n; j++)
//             {
//                 if(arr[i] == arr[j])
//                 {
//                     count++;
//                 }
//             }
//             if(maxCount < count)
//             {
//                 maxCount = count;
//                 ele = arr[i];
//             }
//         }
//         if(maxCount > n/2)
//         {
//             return ele;
//         }
//         else
//             return -1;
//     }
// };
// this the brute force solution whose time complexity is o(n^2).


// class Solution
// {
//     public:
//     int majorityElement(vector <int> arr)
//     {
//         int n = arr.size();
//         map <int, int> mpp;
//         for(int i = 0; i< n; i++)   
//         {
//             mpp[arr[i]]++;
//         }
//         for(auto it : mpp)
//         {
//             if(it.second > n/2)
//             {
//                 return it.first;
//             }
//         }
//         return -1;
//     }
// };
// this is the better solution whose time complexity is o(nlogN) + o(n); Or o(n)+o(n).

class Solution
{
    public:
    int majorityElement(vector <int> arr)
    {
        int ele = 0, count = 0;
        int n = arr.size();
        for(int i = 0; i< n; i++)
        {
            if(count == 0)
            {
                ele = arr[i];
                count = 1;
            }
            else if(ele == arr[i])
            {
                count ++;
            }
            else
            {
                count--;
            }
        }
        int cnt = 0;
        for(auto it : arr)
        {
            if(it == ele)
                cnt++;
        }
        if(cnt > n/2)
            return ele;
        return -1;
    }
};

// this is the optimal solution. using moose voting algo. The time complexity of this code is o(2n);

int main()
{
    vector <int> v = {2, 2, 2,3, 1, 3, 2};
    Solution s;
    int a = s.majorityElement(v);
    cout<< a;
    return 0;
}