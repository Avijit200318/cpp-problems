// // Minimum Index Sum of Two Lists

// Given two arrays of strings list1 and list2, find the common strings with the least index sum.

// A common string is a string that appeared in both list1 and list2.

// A common string with the least index sum is a common string such that if it appeared at list1[i] and list2[j] then i + j should be the minimum value among all the other common strings.

// Return all the common strings with the least index sum. Return the answer in any order.

 

// Example 1:

// Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]
// Output: ["Shogun"]
// Explanation: The only common string is "Shogun".
// Example 2:

// Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KFC","Shogun","Burger King"]
// Output: ["Shogun"]
// Explanation: The common string with the least index sum is "Shogun" with index sum = (0 + 1) = 1.
// Example 3:

// Input: list1 = ["happy","sad","good"], list2 = ["sad","happy","good"]
// Output: ["sad","happy"]
// Explanation: There are three common strings:
// "happy" with index sum = (0 + 1) = 1.
// "sad" with index sum = (1 + 0) = 1.
// "good" with index sum = (2 + 2) = 4.
// The strings with the least index sum are "sad" and "happy".

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n = list2.size();
        int m = list1.size();
        map<string, int> mpp;
        vector<int> hashIdx(n, 0);
        vector<string> ans;
        int minIdx = INT_MAX;

        for(int i = 0; i< m; i++){
            mpp[list1[i]] = i;
        }


        for(int i = 0; i< n; i++){
            if(mpp.find(list2[i]) != mpp.end()){
                int idx = i + mpp[list2[i]];
                minIdx = min(minIdx, idx);
                hashIdx[i] = idx;
            }
            else{
                hashIdx[i] = INT_MAX;
            }
        }

        for(int i = 0; i< n; i++){
            if(hashIdx[i] == minIdx){
                ans.push_back(list2[i]);
            }
        }

        return ans;
    }
};
