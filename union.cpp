#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> uinon(vector<int> a, vector<int> b)
    {
        int n1 = a.size();
        int n2 = b.size();
        int i = 0, j = 0;
        vector<int> v;
        while (i < n1 && j < n2)
        {
            if (a[i] <= b[j])
            {
                if (v.size() == 0 || v.back() != a[i])
                {
                    v.push_back(a[i]);
                }
                i++;
            }
            else
            {
                if (v.size() == 0 || v.back() != b[j])
                {
                    v.push_back(b[j]);
                }
                j++;
            }
        }
        while (i < n1)
        {
            if (v.size() == 0 || v.back() != a[i])
            {
                v.push_back(a[i]);
            }
            i++;
        }
        while (j < n2)
        {
            if (v.size() == 0 || v.back() != b[j])
            {
                v.push_back(b[j]);
            }
            j++;
        }
        return v;
    }
};

int main()
{
    vector<int> a = {1, 1, 2, 3, 4, 5};
    vector<int> b = {2, 3, 4, 5, 5, 6};
    Solution s;
    vector<int> v = s.uinon(a, b);
    for (auto p : v)
    {
        cout << p << " ";
    }
    return 0;
}
// optimal solution . the time complexity o(n1 + n2). this is two pointer method.