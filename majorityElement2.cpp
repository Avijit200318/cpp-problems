#include<bits/stdc++.h>
using namespace std;

// class Solution{
//     public:
//     vector<int> majorityElementNByThree(vector<int> arr, int n)
//     {
//         int count = 0;
//         set<int> ans;
//         for(int i = 0; i< n; i++)
//         {
//             count  = 0;
//             for(int j = 0; j< n; j++)
//             {
//                 if(arr[i] == arr[j])
//                 {
//                     count++;
//                 }
//             }
//             if(count > (n/3))
//             {
//                 ans.insert(arr[i]);
//             }
//             if(ans.size() == 2)
//                 break;
//         }
//        vector<int> vec({ans.begin(), ans.end()});
//         return vec;
//     }
// };

// this is the bruteforce solution whose time complexity is o(n^2)+o(nlogn) or o(n).and space complexity is o(1).

// class Solution{
//     public:
//     vector<int> majorityElementNByThree(vector<int> arr, int n)
//     {
//         map<int, int> mpp;
//         int mini = (n/3)+1;
//         vector<int> ans;
//         for(int i = 0; i< n; i++)
//         {
//             mpp[arr[i]]++;
//             if(mpp[arr[i]] == mini)
//             {
//                 ans.push_back(arr[i]);
//             }
//             if(ans.size() == 2)
//                 break;
//         }
//         return ans;
//     }
// };
// this is the better solution whose time complexity is o(n)+o(nlogn) and space complexity  is o(n).

class Solution{
    public:
    vector<int> majorityElementNByThree(vector<int> arr, int n)
    {
        int el1 = INT_MIN, el2 = INT_MIN;
        int count1 = 0, count2 = 0;
        vector<int> ans;
        for(int i = 0; i< n; i++)
        {
            if(count1 == 0 && arr[i] != el2)
            {
                count1 = 1;
                el1 = arr[i];
            }
            else if(count2 == 0 && arr[i] != el1)
            {
                count2 = 1;
                el2 = arr[i];
            }
            else if(el1 == arr[i])
            {
                count1++;
            }
            else if(el2 == arr[i])
            {
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for(int i = 0; i< n; i++)
        {
            if(arr[i] == el1)
                count1++;
            if(arr[i] == el2)
                count2++;
        }
        if(count1 >= (n/3)+1)
            ans.push_back(el1);
        if(count2 >= (n/3)+1)
            ans.push_back(el2);
        return ans;
    }
};
// this is the optimal solution whose time complexity is o(2n) and space is o(1)

int main()
{
    vector<int> v = {1,1,1,3,3,2,2,2};
    int k = 8;
    Solution s;
    vector<int> a = s.majorityElementNByThree(v, k);
    for(auto it : a)
    {
        cout<< it<< " ";
    }
    return 0;
}