class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        res = []
        ans = []

        for i in range(k):
            while res and nums[i] >= nums[res[-1]]:
                res.pop()
            res.append(i)
        ans.append(nums[res[0]])

        for i in range(k, len(nums)):
            if res and res[0] == i-k:
                res.pop(0)
            while res and nums[i] >= nums[res[-1]]:
                res.pop()
            res.append(i)
            ans.append(nums[res[0]])

        return ans