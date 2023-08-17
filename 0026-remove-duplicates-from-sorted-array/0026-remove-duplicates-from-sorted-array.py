class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n, l, r = len(nums), 0, 1

        while r < n:
            if nums[l] == nums[r]:
                r += 1
            else:
                l += 1
                nums[l] = nums[r]
                r += 1

        return l+1