// Minimum Operations to Exceed Threshold Value II
// You are given a 0-indexed integer array nums, and an integer k.

// In one operation, you will:

// Take the two smallest integers x and y in nums.
// Remove x and y from nums.
// Add min(x, y) * 2 + max(x, y) anywhere in the array.
// Note that you can only apply the described operation if nums contains at least two elements.

// Return the minimum number of operations needed so that all elements of the array are greater than or equal to k.

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
     int n = nums.size();
    multiset<long long> st;
    for(int i = 0; i< n; i++){
        st.insert(nums[i]);
    }
    int count = 0;

     while(true){
        if(*st.begin() < k){
            count++;
            long long x = *st.begin();
            st.erase(st.begin());
            long long y = *st.begin();
            st.erase(st.begin());
            st.insert(x * 2 + y);
        }
        else{
            break;
        }
     }
     return count;
    }
};
