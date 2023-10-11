// [0][0] -> [0][3]
// [0][1] -> [1][3]
// [0][2] -> [2][3]
// [0][3] -> [3][3]
//  i  j      j  (?)
// ....
// so we can say  when i =0 it go to 3 which is n -1 . when i = 1 then it go to 2 which is n -1 -1 . so it is like [n-1-i].

// so the matrix is change like [i][j] -> [j][n-1-i].

#include<bits/stdc++.h>
using namespace std;

// class Solution
// {
//     public:
//     vector <vector<int> > rotateArray(vector <vector <int> > arr)
//     {
//         int n = arr.size();
//         vector <vector <int> > res;
//         res.resize(n, vector<int>(n));
//         // where first n is no of rows and next vector<int>(n) is explain it contain some vector type int whose size is n.
//         // which help us to represent the vector as a empty matrix.
//         for(int i =0; i< n; i++)
//         {
//             for(int j= 0; j< n; j++)
//             {
//                 res[j][n - i -1] = arr[i][j];
//             }
//         }
//         return res;
//     }
// };

// this is the brute force sollution whose time complexity is o(n^2) and space complexity is o(n^2).

class Solution
{
    public:
    vector <vector<int> > rotateArray(vector <vector <int> > arr)
    {
        int n = arr.size();
        for(int i = 0; i< n-1 ; i++)
        {
            for(int j = i+1; j<= n-1; j++)
            {
                swap(arr[i][j], arr[j][i]);
            }
        }

        for(int i = 0; i< n; i++)
        {
            reverse(arr[i].begin(), arr[i].end());
        }
        return arr;
    }
};
// this the better and optimal solution the time complexity of this code is o(n/2*n/2)+o(n*n/2) and the space complexity is o(1).


int main()
{
    vector <vector <int> > v = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    Solution s;
    auto a = s.rotateArray(v);
    int n = a.size();
    for(int i = 0; i< n; i++)
    {
        for(int j= 0; j< n; j++)
        {
            cout<< a[i][j]<< " ";
        }
        cout<< endl;
    }
    return 0;
}