class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        hs = {}
        
        for i, n in enumerate(nums):
            if n in hs and i - hs[n] <= k:
                return True
            hs[n] = i
        
        return False