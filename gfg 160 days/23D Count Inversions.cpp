// Count Inversions
// Difficulty: MediumAccuracy: 16.93%Submissions: 631K+Points: 4
// Given an array of integers arr[]. Find the Inversion Count in the array.
// Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
// If an array is sorted in the reverse order then the inversion count is the maximum. 

// Examples:

// Input: arr[] = [2, 4, 1, 3, 5]
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).


// using mergesort
class Solution {
  public:
    // Function to count inversions in the array.
    int merge(vector<int> &arr, int low, int mid, int high){
        int left = low, right = mid+1;
        
        vector<int> temp;
        int count = 0;
        
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
                count += (mid - left + 1);
            }
        }
        
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i = low; i<= high; i++){
            arr[i] = temp[i - low];
        }
        
        return count;
    }
    
    int mergeSort(vector<int> &arr, int low, int high){
        int n = arr.size();
        
        if(low >= high) return 0;
        
        int mid = (low + high)/2;
        
        int count = 0;

      // the bellow two count by default give us 0 when the array become single element. but we set here count because when we merge again the element then the count is return through the mergeSort function
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid+1, high);
        
        count += merge(arr, low, mid, high);
        
        return count;
    }
    
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        return mergeSort(arr, 0, n-1);
    }
};
