#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector <int> intersection(vector <int> a, vector <int> b)
    {
        int n1 = a.size();
        int n2 = b.size();
        vector <int> ans;
        int i = 0, j = 0;
        while(i < n1 && j < n2)
        {
            if(a[i] < b[j])
            {
                i++;
            }
            else if(a[i] > b[j])
            {
                j++;
            }
            else
            {
                ans.push_back(a[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};

int main()
{
    vector <int> a = {1, 2, 2, 3, 3, 4, 5, 6};
    vector <int> b = {2, 3, 5, 6, 6, 7};
    Solution s;
    vector <int> v = s.intersection(a,b);
    for(auto p : v)
    {
        cout<< p << " ";
    }
    return 0;
}
// optimal solution . the time complexity o(n1 + n2). this is two pointer method.