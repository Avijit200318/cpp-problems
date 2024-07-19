// the first value not start from 1
// the first value is start from arr[0]
// so we find the value with respect to arr[0]
// check and leetcode and gfg website

int KthMissingElement(int a[], int n, int k)
{
    int low = 0, high = n-1;
    int diff = 0;
    int missing = -1;
  // if the first value did not start from 1 then find the difference
  
    if(a[0] != 1)
    {
        diff = a[0] -1;
    }
    while(low <= high)
    {
        int mid = (low + high)/2;
      // modify this line
        missing = a[mid] - (mid +1 + diff);
        if(missing < k)
        {
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
  // modify this line
    int value = high + 1 + k + diff;
  // if the value is high from the max value from the last value from array.
    if(value > a[n-1])
    return -1;
    return value;
}
