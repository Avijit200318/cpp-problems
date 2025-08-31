// Non-overlapping Intervals
// Input: intervals[][] = [[1, 2], [2, 3], [3, 4], [1, 3]]
// Output: 1
// Explanation: [1, 3] can be removed and the rest of the intervals are non-overlapping.

// Input: intervals[][] = [[1, 3], [1, 3], [1, 3]]
// Output: 2
// Explanation: You need to remove two [1, 3] to make the rest of the intervals non-overlapping.


// 1st we need to sort the array
// 2nd find overlapping
// [1, 2] & [1, 3]
// we will convert it [1, 2] so for the 1th index instead of saving the max value we just need to save the min value of (ans.back()[1]) and (intervalas[i][1])
// lastly return the size difference

class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
     sort(intervals.begin(), intervals.end());
     int n = intervals.size();
     vector<vector<int>> ans;
     
     for(int i = 0; i< n; i++){
         if(ans.size() == 0 || ans.back()[1] <= intervals[i][0]){
             ans.push_back(intervals[i]);
         }
         else{
             ans.back()[1] = min(ans.back()[1], intervals[i][1]);
         }
     }
     return intervals.size() - ans.size();
    }
};
