#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector <int> removeDup(vector <int> arr)
    {
        int n = arr.size();
        vector <int> ve;
        set <int> s;
        for(auto p : arr)
        {
            s.insert(p);
        }
        
        for(auto p : s){
            ve.push_back(p);
        }
        return ve;
    }
};

int main()
{
    vector<int> v = {1, 1, 2, 3, 3, 4, 5};
    Solution s;
    vector<int> a = s.removeDup(v);

    for(auto p : a){
        cout << p <<" ";
    }
    return 0;
}
// the time complexity of this code is o(n);
