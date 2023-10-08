#include<bits/stdc++.h>
using namespace std;

// class Solution
// {
//     public:
//     vector <int> rearrangeNumberBySign(vector <int> arr)
//     {
//         vector <int> pos, neg;
//         for(auto it : arr)
//         {
//             if(it < 0)
//             {
//                 neg.push_back(it);
//             }
//             else{
//                 pos.push_back(it);
//             }
//         }
//         for(int i = 0; i< arr.size()/2 ; i++)
//         {
//             arr[2*i] = pos[i];
//             arr[2*i + 1] = neg[i];
//         }
//         return arr;
//     }
// };
// the time complexity of this code is o(n)+o(n/2).

class Solution
{
    public:
    vector <int> rearrangeNumberBySign(vector <int> arr)
    {
        int posIdx = 0, negIdx = 1, n = arr.size();
        vector <int> v(n, 0);
        for(int i = 0; i< n; i++)
        {
            if(arr[i] < 0)
            {
                v[negIdx] = arr[i];
                negIdx += 2;
            }
            else
            {
                v[posIdx] = arr[i];
                posIdx += 2;
            }
        }
        return v;
    }
};
// the time complexity of this code is o(n).to insert 0 in the vector  take o(1) time complexity.

int main()
{
    vector <int> v = {3, 1, -2, -5, 2, -4};
    Solution s;
    vector <int> a = s.rearrangeNumberBySign(v);
    for(auto it : a)
    {
        cout<< it<<" ";
    }
    return 0;
}