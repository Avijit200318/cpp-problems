// 3. K Sized Subarray Maximum -> gfg

// Input: arr[] = [1, 2, 3, 1, 4], k = 3
// Output: [3, 3, 4]
// Explanation: 
// 1st contiguous subarray [1, 2, 3], max = 3
// 2nd contiguous subarray [2, 3, 1], max = 3
// 3rd contiguous subarray [3, 1, 4], max = 4

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        multiset<int> st;
        int n = arr.size(), start = 0;
        vector<int> ans;
        
        for(int i = 0; i< n; i++){
            st.insert(arr[i]);
            
            if(i - start + 1 > k){
                // remove only one occurance from the array
                st.erase(st.find(arr[start]));
                start++;
            }
            
            // if the index size is reaches to k or greater then use this
            if(i+1 >= k){
            ans.push_back(*st.rbegin());
            }
        }
        return ans;
    }
};