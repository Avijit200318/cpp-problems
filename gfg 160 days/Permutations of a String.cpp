// Permutations of a String

// Given a string s, which may contain duplicate characters, your task is to generate and return an array of all unique permutations of the string. You can return your answer in any order.

// Examples:

// Input: s = "ABC"
// Output: ["ABC", "ACB", "BAC", "BCA", "CAB", "CBA"]
// Explanation: Given string ABC has 6 unique permutations.


// for strings

class Solution {
  public:
  void recursivePermutation(string s,set<string> &ans, int index){
      if(index >= s.size()){
          ans.insert(s);
          return;
      }
      
      for(int i = index; i< s.size(); i++){
          swap(s[index], s[i]);
        recursivePermutation(s, ans, index+1);
        swap(s[index], s[i]);
      }
  }
  
    vector<string> findPermutation(string &s) {
        set<string> ans;
        int index = 0;
        recursivePermutation(s, ans, index);
        return vector<string>(ans.begin(), ans.end());
    }
};


// for array of integers. with distinct values means not like [1,1,1]. if this type is also available do like the string solution

class Solution {
public:
    void helper(vector<int> nums, vector<vector<int>> &ans, int index){
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = index; i< nums.size(); i++){
            swap(nums[index], nums[i]);
            helper(nums, ans, index+1);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        helper(nums, ans, index);
        return ans;
    }
};
