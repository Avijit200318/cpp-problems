# 2064. Minimized Maximum of Products Distributed to Any Store
# You are given an integer n indicating there are n specialty retail stores. There are m product types of varying amounts, which are given as a 0-indexed integer array quantities, where quantities[i] represents the number of products of the ith product type.

# You need to distribute all products to the retail stores following these rules:

# A store can only be given at most one product type but can be given any amount of it.
# After distribution, each store will have been given some number of products (possibly 0). Let x represent the maximum number of products given to any store. You want x to be as small as possible, i.e., you want to minimize the maximum number of products that are given to any store.
# Return the minimum possible x.

import math
class Solution:
    # how to calculate or distribute product quantities to each store? we have to check how much quantities we can set for a single store like if we have 11 quantities and we want to set 3 to each then there will be 4 stores who get product quantities like 3, 3, 3, 2 -> the ceil value

    def helper(self, arr, amount):
        cnt = 0

        for i in range(len(arr)):
            cnt += math.ceil(arr[i]/amount)

        return cnt

    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        m = len(quantities)
        maxVal = float('-inf')
        ans = -1

        # we can either put 1 product to each store or we can put the maximum product quantities to a single store
        # we have to provide some values to each store then we need to take maximum. that is question asked

        for i in range(m):
            maxVal = max(maxVal, quantities[i])

        low = 1
        high = maxVal

        while low <= high:
            mid = (low + high) // 2

            cnt = self.helper(quantities, mid)

            if cnt <= n:
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
        
        return ans