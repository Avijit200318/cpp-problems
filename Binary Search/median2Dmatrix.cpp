/*
You are given a row-wise sorted matrix 'mat' of size m x n where 'm' and 'n' are the numbers of rows and columns of the matrix, respectively.

Your task is to find and return the median of the matrix.
Input: 'n' = 5, 'm' = 5
'mat' = 
[     [ 1, 5, 7, 9, 11 ],
      [ 2, 3, 4, 8, 9 ],
      [ 4, 11, 14, 19, 20 ],
      [ 6, 10, 22, 99, 100 ],
      [ 7, 15, 17, 24, 28 ]   ]

Output: 10
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int upperBound(vector<int> arr, int target)
    {
        int n = arr.size();
        int ans = n;
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] > target)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }

    int countSmallEqual(vector<vector<int>> &matrix, int n, int m, int x)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += upperBound(matrix[i], x);
        }
        return cnt;
    }

    int median(vector<vector<int>> &matrix, int m, int n)
    {
        int low = INT_MAX, high = INT_MIN;
        n = matrix.size();
        m = matrix[0].size();
        for (int i = 0; i < n; i++)
        {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][m - 1]);
        }

        int req = (m * n) / 2;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int smallEq = countSmallEqual(matrix, n, m, mid);
            if (smallEq <= req)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};

int main()
{
    vector<vector<int>> mat = {{ 1, 5, 7, 9, 11 },{ 2, 3, 4, 8, 9 },{ 4, 11, 14, 19, 20 },{ 6, 10, 22, 99, 100 },{ 7, 15, 17, 24, 28 }};
    int n = mat.size();
    int m = mat[0] .size();
    Solution s;
    int ans = s.median(mat, n, m);
    cout<< ans;
    return 0;
}