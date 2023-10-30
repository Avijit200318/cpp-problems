#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void binarySearch(int *arr, int size, int k)
    {
        int low = 0, high = size-1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(arr[mid] == k)
            {
                cout<< "the number "<< k << "is present in the array.";
            }
            else if(arr[mid] < k)
            {
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
    }
};

int main()
{
    int v[] = {1,2,3,4,5,6};
    int size = 6;
    int n;
    cout<< "enter the number you want to search:";
    cin>> n;
    Solution s;
    s.binarySearch(v, 6, n);
    return 0;
}