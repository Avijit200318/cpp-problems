// Geek has two sorted arrays a and b having n elements each and two integers x and y. A pair of indices (p.q) is called a strong index if 
// ap - x <<< bqap + y. Find maximum number of strong indices (p.q) such that p is an index of an array a and q is an index of an array b.
// Any index from array a can be matched to atmost one index from array b. Similarly, any index from array b can be matched to atmost one
// index from array a.

class Solution {
  public:
    int maximumStrongIndices(int n, int x, int y, vector<int> &a, vector<int> &b) {
        int i = 0, j = 0;
        int count = 0;
        while(i < n && j < n)
        {
            if(!(a[i] - x <= b[j]))
            {
                j++;
            }
            else if(!(a[i] + y >= b[j]))
            {
                i++;
            }
            else
            {
                count ++;
                i++;
                j++;
            }
        }
        return count;   
    }
};
