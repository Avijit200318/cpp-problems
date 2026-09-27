// Top K Frequent Elements

// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.


// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2

// Output: [1,2]

// Example 2:

// Input: nums = [1], k = 1

// Output: [1]

// Example 3:

// Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

// Output: [1,2]

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        vector<int> ans;

        for(int i = 0; i< n; i++){
            mpp[nums[i]]++;
        }
        
        vector<pair<int, int>> temp;
        for(auto it : mpp){
            temp.push_back({it.second, it.first});
        }

        sort(temp.begin(), temp.end());

        for(int i = 0; i< k; i++){
            ans.push_back(temp[temp.size()-1-i].second);
        }
        return ans;
    }
};

// incase of python we don't have pari so we need to store it into a list of tupple
// class Solution:
// 	def topKFreq(self, arr, k):
// 		# Code here
// 		n = len(arr)
// 		mpp = {}
		
// 		for i in range(n):
// 		    if arr[i] not in mpp:
// 		        mpp[arr[i]] = 1
// 		    else:
// 		        mpp[arr[i]] += 1
		
// 		temp = []    
// 		for key, value in mpp.items():
// 		    temp.append((value, key))
		
// 		temp.sort()
// 		size = len(temp)
// 		ans = []
		
// 		for i in range(k):
// 		    ans.append(temp[size-1-i][1])
		    
// 		return ans