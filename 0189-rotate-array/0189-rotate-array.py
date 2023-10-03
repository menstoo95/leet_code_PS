class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        tmp = copy.deepcopy(nums)

        for i in range(len(nums)):
            nums[(i+k)%len(nums)] = tmp[i]
        