//Smallest Positive Missing
//Difficulty: MediumAccuracy: 25.13%Submissions: 393K+Points: 4
//You are given an integer array arr[]. Your task is to find the smallest positive number missing from the array.

//Note: Positive number starts from 1. The array can have negative integers too.

//Input: arr[] = [2, -3, 4, 1, 1, 7]
// Output: 3
// Explanation: Smallest positive missing number is 3.

//Input: arr[] = [5, 3, 2, 5, 1]
// Output: 4
// Explanation: Smallest positive missing number is 4.

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        int res = 1;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i = 0; i< n; i ++){
            if(res == arr[i]){
                res++;
            }
            if(res < arr[i]){
                return res;
            }
        }
        return res;
    }
};
