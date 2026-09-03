# Maximum Candies Allocated to K Children

# You are given a 0-indexed integer array candies. Each element in the array denotes a pile of candies of size candies[i]. You can divide each pile into any number of sub piles, but you cannot merge two piles together.

# You are also given an integer k. You should allocate piles of candies to k children such that each child gets the same number of candies. Each child can be allocated candies from only one pile of candies and some piles of candies may go unused.

# Return the maximum number of candies each child can get.

 

# Example 1:

# Input: candies = [5,8,6], k = 3
# Output: 5
# Explanation: We can divide candies[1] into 2 piles of size 5 and 3, and candies[2] into 2 piles of size 5 and 1. We now have five piles of candies of sizes 5, 5, 3, 5, and 1. We can allocate the 3 piles of size 5 to 3 children. It can be proven that each child cannot receive more than 5 candies.
# Example 2:

# Input: candies = [2,5], k = 11
# Output: 0
# Explanation: There are 11 children but only 7 candies in total, so it is impossible to ensure each child receives at least one candy. Thus, each child gets no candy and the answer is 0.


import math

class Solution:
    def helper(self, arr, share):
        sumAns = 0
        for i in range(len(arr)):
            sumAns += math.floor(arr[i]/share)
            # we need to calculate the floor value to know how many children can get same ammount candies
        return sumAns

    def maximumCandies(self, candies: List[int], k: int) -> int:
        n = len(candies)

        sumAns = 0
        maxVal = float('-inf')
        ans = float('-inf')

        for i in range(n):
            sumAns += candies[i]
            maxVal = max(maxVal, candies[i])

        if sumAns < k:
            return 0
        
        # for i in range(maxVal, 0, -1):
        #     cnt = self.helper(candies, i)
        #     if cnt >= k:
        #         return i
            
        # return -1

        low = 1
        high = maxVal
        

        while low <= high:
            mid = (low + high) // 2
            cnt = self.helper(candies, mid)

            
            if cnt >= k:
                low = mid + 1
                ans = max(ans, mid)
            else:
                high = mid - 1
                
        
        return ans

        