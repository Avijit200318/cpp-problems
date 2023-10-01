#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector <int> rotateLeft(vector<int> arr, int d)
    {
        int n = arr.size();
        d = d % n; // To handle cases where d is greater than the size of the array
        reverse(arr.begin(), arr.begin() + d);
        reverse(arr.begin() + d, arr.end());
        reverse(arr.begin(), arr.end());
        return arr;
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    int d;
    cout << "enter the number of times you want to left rotate:";
    cin >> d;
    Solution s;
    vector <int> a = s.rotateLeft(v, d);
    for(auto p : a){
        cout << p << " ";
    }
    return 0;
}
// the time complexity of this code is o(d) + o(n-d) + o(n) = o(2n).we use here the reverse method.this is the optimal soln.
