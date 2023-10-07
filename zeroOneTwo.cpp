#include<bits/stdc++.h>
using namespace std;

// brute force solution is sorting method . o(nlogn).

// class Solution
// {
//     public:
//     vector <int> zeroOneTwo(vector <int> arr)
//     {
//         int count0 = 0, count1 = 0, count2 = 0;
//         for(auto p : arr)
//         {
//             if(p == 0)
//                 count0++;
//             else if(p == 1)
//                 count1++;
//             else
//                 count2++;
//         }

//         for(int i = 0; i< count0; i++)
//             arr[i] = 0;
//         for(int i = 0; i< count1; i++)
//             arr[i+count0] = 1;
//         for(int i = 0; i< count2; i++)
//             arr[i+count1+count0] = 2;
//         // if count0 = 3, count1 = 4, cont2 = 5
//         return arr;
//     }
// };

// the time complexity of this code is o(2n);

class Solution
{
    public:
    vector <int> zeroOneTwo(vector <int> arr)
    {
        int low = 0, mid = 0, heigh = arr.size() -1;
        while(mid <= heigh)
        {
            if(arr[mid] == 0) 
            {
                swap(arr[mid], arr[low]);
                mid++;
                low++;
            }
            else if(arr[mid] == 1)
            {
                mid++;
            }
            else{
                swap(arr[mid], arr[heigh]);
                heigh --;
            }
        }
        return arr;
    }
};

// the time complexity is o(n). this is the optimal solution.

int main()
{
    vector <int> v = {0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 0, 0, 1};
    Solution s;
    vector <int> a = s.zeroOneTwo(v);
    for(auto p : a)
    {
        cout<< p<< " ";
    }
    return 0;
}