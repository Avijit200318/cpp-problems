#include<bits/stdc++.h>
using namespace std;

// class Solution
// {
//     public:
//     vector<vector <int>> markRow(int i, vector<vector<int>> v)
//     {
//         int m = v[0].size();
//         for(int j = 0; j< m; j++)
//         {
//             if(v[i][j] != 0)
//             {
//                 v[i][j] = -1;
//             }
//         }
//         return v;
//     }

//     vector<vector <int>> markColumn(int j, vector<vector <int>> v)
//     {
//         int n = v.size();
//         for(int i = 0; i< n; i++)
//         {
//             if(v[i][j] != 0)
//             {
//                 v[i][j] = -1;
//             }
//         }
//         return v;
//     }

//     vector < vector <int> > setZeroToMatrix(vector < vector <int> > arr)
//     {
//         int n = arr.size();
//         int m = arr[0].size();
//         for(int i = 0; i< n; i++)                
//         {
//             for(int j = 0; j< m; j++)
//             {
//                 if(arr[i][j] == 0)
//                 {
//                     arr = markRow(i, arr);
//                     arr = markColumn(j, arr);
//                 }
//             }
//         }

//         for(int i = 0; i< n; i++)
//         {
//             for(int j =0; j< m ;j++)
//             {
//                 if(arr[i][j] == -1)
//                 {
//                     arr[i][j] = 0;
//                 }
//             }
//         }
//         return arr;
//     }
// };

// this is the brute force solution. whose time complexity is o(n*m)+o(n)+o(m) +o(n*m)

// class Solution
// {
//     public:
//     vector < vector <int> > setZeroToMatrix(vector < vector <int> > arr)
//     {
//         int n = arr.size();
//         int m = arr[0].size();
//         vector <int> row, column;
//         row.resize(n,0);
//         column.resize(n,0);
//         // this line means the size of the column is n and it containe all 0s.
//         for(int i =0; i< n; i++)
//         {
//             for(int j = 0; j< m; j++)
//             {
//                 if(arr[i][j] == 0)
//                 {
//                     row[i] = 1;
//                     column[j] = 1;
//                 }
//             }
//         }

//         for(int i = 0; i< n; i++)
//         {
//             for(int j = 0; j< m; j++)
//             {
//                 if(row[i] || column[j])
//                 {
//                     arr[i][j] = 0;
//                 }
//             }
//         }
//         return arr;
//     }
// };
// the time complexity of this code is o(2*n*m) and the space complexity is o(n)+o(m)


class Solution
{
    public:
    vector < vector <int> > setZeroToMatrix(vector < vector <int> > arr)
    {
        int n = arr.size();
        int m = arr[0].size();
        int col0 = 1;
        for(int i = 0; i< n; i++)
        {
            for(int j = 0; j< m; j++)
            {
                if(arr[i][j] == 0)
                {
                    arr[i][0] = 0;
                    if(j != 0)
                    {
                    arr[0][j] = 0;
                    }
                    else{
                        col0 = 0;
                    }
                }
            }
        }

        for(int i = 1; i< n; i++)
        {
            for(int j = 1; j< m; j++)
            {
                if(arr[i][j] != 0)
                {
                    if(arr[i][0] == 0 || arr[0][j] == 0)
                    {
                        arr[i][j] = 0;
                    }
                }
            }
        }
        if(arr[0][0] == 0)
        {
            for(int i = 0; i< m; i++)
                arr[0][i] = 0;
        }
        if(col0 == 0)
        {
            for(int j = 0; j< n; j++)
                arr[j][0] = 0;
        }
        return arr;
    }
};

// this is the optimal solution whose time complexity is o(n*m)+o(n*m) = o(2*n*m) and space complexity is o(1).

int main()
{
    // vector <vector <int> > v = {{1, 1, 1, 1}, {1, 0, 0, 1}, {1,1,0, 1}, {1,1,1,1}};
    vector <vector <int> > v = {{1, 1, 1, 1}, {1, 0, 1, 1}, {1,1,0, 1}, {0,1,1,1}};
    Solution s;
    auto a = s.setZeroToMatrix(v);
    int n = a.size();
    int m = a[0].size();
    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j< m; j++)
        {
            cout<< a[i][j] << " ";
        }
        cout<<endl;
    }
    return 0;
}