// Summary Ranges

// Input: nums = [0,1,2,4,5,7]
// Output: ["0->2","4->5","7"]
// Explanation: The ranges are:
// [0,2] --> "0->2"
// [4,5] --> "4->5"
// [7,7] --> "7"

//   Example 2:

// Input: nums = [0,2,3,4,6,8,9]
// Output: ["0","2->4","6","8->9"]
// Explanation: The ranges are:
// [0,0] --> "0"
// [2,4] --> "2->4"
// [6,6] --> "6"
// [8,9] --> "8->9"
  
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        if(n == 0) return ans;
        int start = nums[0];
        if(n==1){
            ans.push_back(to_string(nums[0]));
            return ans;
        }

        for(int i = 1; i< n; i++){
            string s = "";
        
            if(nums[i] != nums[i-1] + 1){
                if(start == nums[i-1]){
                    ans.push_back(to_string(nums[i-1]));
                }
                else{
                s = to_string(start) + "->" + to_string(nums[i-1]);
                ans.push_back(s);
                }
                start = nums[i];
            }
        }
        if(start == nums[n-1]){
            ans.push_back(to_string(start));
        }
        else{
            string s;
            s = to_string(start) + "->" + to_string(nums[n-1]);
                ans.push_back(s);
        }
        return ans;
    }
};
