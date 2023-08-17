class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        j = 0

        for i in range(len(nums)):
            if nums[i] == val:
                j += 1
            else:
                nums[i-j] = nums[i]
        
        return len(nums) - j