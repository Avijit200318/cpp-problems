# Max Sum Subarray of size K
# Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.

# Note: A subarray is a contiguous part of any given array.

# Examples:

# Input: arr[] = [100, 200, 300, 400], k = 2
# Output: 700
# Explanation: arr2 + arr3 = 700, which is maximum.

class Solution:
    def maxSubarraySum(self, arr, k):
        # code here 
        n = len(arr)
        sumAns = 0
        left = 0
        maxi = float('-inf')
        
        for right in range(n):
            sumAns += arr[right]
            
            if(right - left + 1 > k):
                sumAns -= arr[left]
                left += 1
            
            maxi =max(maxi, sumAns)
        return maxi
        