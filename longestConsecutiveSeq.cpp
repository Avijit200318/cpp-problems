// [102, 4, 100, 1, 101, 3, 2, 1,1]

#include<bits/stdc++.h>
using namespace std;

// class Solution
// {
//     public:
//     bool ls(vector <int> v, int k)
//     {
//         int n = v.size();
//         for(int i = 0; i< n; i++)
//         {
//             if(v[i] == k)
//             {
//                 return true;
//             }
//         }
//         return false;
//     }

//     int longestConsecutiveSeq(vector <int> arr)
//     {
//         int n = arr.size();
//         int maxLen = 1;
//         int count = 1;
//         for(int i = 0 ; i< n; i++)
//         {
//             int x = arr[i];
//             count = 1;
//             while(ls(arr, x+1) == true)
//             {
//                 x = x+1;
//                 count ++;
//             }
//             maxLen = max(maxLen, count);
//         }
//         return maxLen;
//     }
// };
// the time complexity of this code is o(n^2).this is the brute force solution.


// class Solution
// {
//     public:
//     int longestConsecutiveSeq(vector <int> arr)
//     {
//         int n = arr.size();
//         sort(arr.begin(), arr.end());
//         // [1, 1, 1, 2, 3, 4, 100, 101, 102]
//         int lastSeq = INT_MIN, largest = 1;
//         int count = 0;
//         for(int i = 0; i< n; i++)
//         {
//             if(arr[i] - 1 == lastSeq)
//             {
//                 lastSeq = arr[i];
//                 count++;
//             }
//             else if(arr[i] != lastSeq)
//             {
//                 lastSeq = arr[i];
//                 count = 1;
//             }
//             largest = max(largest, count);
//         }
//         return largest;
//     }
// };
// this is the better solution whose time complexity is o(nlogn)+o(n)

class Solution
{
    public:
    int longestConsecutiveSeq(vector <int> arr)
    {
        int n = arr.size();
        unordered_set <int> m;
        int largest = 1;
        for(int i = 0; i< n; i++)
        {
            m.insert(arr[i]);
        }

        for(auto it : m)
        {
            if(m.find(it - 1) == m.end())
            {
                int x = it;
                int count = 1;
                while(m.find(x+1) != m.end())
                {
                    x = x+1;
                    count ++;
                }
                largest = max(largest, count);
            }
        }
        return largest;
    }
};

// the time complexity of this code is o(3n). here the while loop did not take n iteration for each loop . it takes total n iteration when the for loop is end so the time complexity is o(n)+o(n)+o(n) = o(3n).this is the optimal solution. space complexity is o(N).

int main()
{
    // vector <int> v = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    vector <int> v = {102, 99, 100, 1, 101, 3, 2, 103};
    Solution s;
    int a = s.longestConsecutiveSeq(v);
    cout<< a;
    return 0;
}