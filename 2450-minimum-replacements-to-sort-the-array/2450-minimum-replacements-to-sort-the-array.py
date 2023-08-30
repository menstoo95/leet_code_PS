class Solution:
    def minimumReplacement(self, nums: List[int]) -> int:
        prev, ans = nums[-1], 0

        for i in range(len(nums)-2,-1,-1):
            if prev < nums[i]:
                res = nums[i]//prev + (0 if nums[i]%prev == 0 else 1)
                ans += res - 1
                prev = nums[i]//res
            else:
                prev = nums[i]
        
        return ans
