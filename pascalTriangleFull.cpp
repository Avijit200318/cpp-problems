// the brute method the time complexityis o(n*n*r).
// better solution o(r*r).
// the bellow is the optimal solution.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> createRow(int r)
    {
        int row = r;
        int ans = 1;
        vector<int> arr;
        arr.push_back(1);
        for (int i = 1; i < row; i++)
        {
            ans = ans * (row - i) / i;
            arr.push_back(ans);
        }
        return arr;
    }
    vector<vector<int>> printFullPascalTriangle(int r)
    {
        vector<vector<int>> res;
        for (int i = 1; i <= r; i++)
        {
            res.push_back(createRow(i));
            
        }

        return res;
    }
};
// this is the optimal solution and the time complexity of this code is o(r*r). and space complexity is o(n)+o(n*n).

int main()
{
    int r = 6;
    Solution s;
    vector<vector<int>> a = s.printFullPascalTriangle(r);
    int n = a.size();
    // int m = a[0].size();     the size of m is change for each element in the pascal so if we define it like this then it set as an constant which cause the problem.insetead of this we just use inside the loop like arr[i].size().
    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j< a[i].size(); j++)
        {
            cout<< a[i][j] <<" ";
        }
        cout<<endl;
    }
    return 0;
}