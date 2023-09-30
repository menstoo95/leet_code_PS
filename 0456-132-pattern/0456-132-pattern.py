class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        arr = []
        tmp = -0x3f3f3f3f

        for i in range(len(nums)-1, -1, -1):
            if nums[i] < tmp:
                return True
            else:
                while arr and arr[-1] < nums[i]:
                    tmp = arr[-1]
                    arr.pop()
            
            arr.append(nums[i])
        

        return False
        