// [3, 1, 2] ans is [3, 2, 1]. and it the input is [3, 2,1] => [1,2,3]
// [2, 1, 5, 4, 3, 0, 0]

// step 1 : find the break point
// step 2 : find the nubmer minimum number that is bigger than break point number.and swap it.
// step 3: sort or reverse the remaining form the swap position.

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public: 
    vector <int> nextPermutation(vector <int> arr)
    {
        int n = arr.size();
        int idx = -1;
        for(int i = n-2; i>= 0; i--)
        {
            if(arr[i] < arr[i+1])
            {
                idx = i;
                break;
            }
        }

        if(idx == -1)
        {
            reverse(arr.begin(), arr.end());
            return arr;
        }

        for(int i = n-1; i>= 0; i--)
        {
            if(arr[idx] < arr[i])
            {
                swap(arr[idx], arr[i]);
                break;
            }
        }
        reverse(arr.begin()+idx+1, arr.end());
        return arr;
    }
};

// the complexity of the code is o(n)+o(n)+o(n) = O(3n) [the reverse also give a time complexity of o(n)]. this the optimal solution also.

// we also have an c++ stl next_permutaion() which give us the same answer.

int main()
{
    vector <int> v = {2, 1, 5 , 4, 3, 0, 0};
    Solution s;
    vector <int> a = s.nextPermutation(v);
    for(auto it : a)
    {
        cout<< it<< " ";
    }
    return 0;
}