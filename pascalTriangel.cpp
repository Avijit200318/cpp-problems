// here given row and column you have to return the element of the pascal triangle.ex r = 6, c= 1 -> output: 5.

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int pascalTriangelElement(int r, int c)
    {
        int row = r -1, col = c -1;
        // we have formula rCc = is the element. but it also take too much time complexitywhich is a brute force solution.
        // observation 5C2= 5!/2!3! = 5/2*4/1 -> so r is depend on how much the loop goes if here 2 -> 3 change then the answer become 5!/3!2! = 5/3*4/2*3/1 or we can write it like this 5/1*4/2*3/3;
        int sum = 1;
        for(int i = 0; i< col; i++)
        {
            sum = sum*(row - i);
            sum = sum/(i+1);
        }
        return sum;
    }
};
// this is  the optimal solution whose time complexity is o(c) [c = no of column] and space complexity is o(1).

int main()
{
    // int r = 6, c = 2;
    int r = 6, c = 3;
    Solution s;
    int a = s.pascalTriangelElement(r,c);
    cout<< a;
    return 0;
}