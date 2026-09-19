// Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

// Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

 

// Example 1:

// Input: nums = [8,2,4,7], limit = 4
// Output: 2 
// Explanation: All subarrays are: 
// [8] with maximum absolute diff |8-8| = 0 <= 4.
// [8,2] with maximum absolute diff |8-2| = 6 > 4. 
// [8,2,4] with maximum absolute diff |8-2| = 6 > 4.
// [8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
// [2] with maximum absolute diff |2-2| = 0 <= 4.
// [2,4] with maximum absolute diff |2-4| = 2 <= 4.
// [2,4,7] with maximum absolute diff |2-7| = 5 > 4.
// [4] with maximum absolute diff |4-4| = 0 <= 4.
// [4,7] with maximum absolute diff |4-7| = 3 <= 4.
// [7] with maximum absolute diff |7-7| = 0 <= 4. 
// Therefore, the size of the longest subarray is 2.
// Example 2:

// Input: nums = [10,1,2,4,7,2], limit = 5
// Output: 4 
// Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
// Example 3:

// Input: nums = [4,2,2,2,4,4,2,2], limit = 0
// Output: 3


class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int> st;
        int left = 0;
        int maxLen = 0;

        for(int right = 0; right < n; right++){
            st.insert(nums[right]);
            int diff = abs(*st.begin() - *st.rbegin());

            while(diff > limit){
                st.erase(st.find(nums[left]));
                diff = abs(*st.begin() - *st.rbegin());
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};



// or


// Monotonic Queue Window method
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0;
        int n = nums.size();
        int ans = 0;

        deque<int> maxQ, minQ;

        // maxQ -> will store all the index value that have high value than next one
        // minQ -> will store all the index value where the current value is low than the next one.
        for(int right = 0; right < n; right++){
            while(!maxQ.empty() && nums[maxQ.back()] <= nums[right]){
                maxQ.pop_back();
            }
            maxQ.push_back(right);
            
            while(!minQ.empty() && nums[minQ.back()] >= nums[right]){
                minQ.pop_back();
            }
            minQ.push_back(right);
            
            while(nums[maxQ.front()] - nums[minQ.front()] > limit){
                // if it outof limit then we need to reduce the window size
                // if left index is present then remove it
                if(maxQ.front() == left){
                    maxQ.pop_front();
                }
                
                if(minQ.front() == left){
                    minQ.pop_front();
                }
                
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};