#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector <int> moveZeroLast(vector <int> arr)
    {
        int n = arr.size();
        int j = -1;
        for(int i = 0; i< n ; i++){
            if(arr[i] == 0){
                j = i;
                break;
            }
        }

        for(int i = j+1; i< n; i++)
        {
            if(arr[i] != 0){
                swap(arr[i], arr[j]);
                j++;
            }
        }
        return arr;
    }
};

int main()
{
    vector <int> v = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    Solution s;
    vector <int> a = s.moveZeroLast(v);
    for(auto p : a)
    {
        cout<< p << " ";
    }
    return 0;
}
// this is the two pointer approach. the time complexity of this code is o(n).optimal soln.