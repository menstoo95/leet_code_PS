class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        nums = list(set(nums))
        l, r = 0, len(nums)-1

        while l < r:
            mid = (l+r)//2
            
            if nums[mid] >= nums[r]:
                l = mid+1
            else:
                r = mid
        
        pivot = l
        l, r = 0, len(nums)-1

        while l <= r:
            mid = (l+r)//2
            rotmid = (mid+pivot)%len(nums)
            if nums[rotmid] < target:
                l = mid+1
            elif nums[rotmid] == target:
                return True
            else:
                r = mid-1

        return False