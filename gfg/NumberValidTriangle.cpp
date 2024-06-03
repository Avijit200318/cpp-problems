// Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take
// them as side lengths of a triangle.


// Input: nums = [2,2,3,4]
// Output: 3
// Explanation: Valid combinations are: 
// 2,3,4 (using the first 2)
// 2,3,4 (using the second 2)
// 2,2,3
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int n = nums.size(), k= n-1; k > 1; k-- )   
        {
            int i = 0, j = k -1;
            while(i < j)
            {
                if(nums[i] + nums[j] > nums[k])
                {
                    count += --j - i + 1;
                }
                else
                    i++;
            }
        }
        return count;
    }
};
