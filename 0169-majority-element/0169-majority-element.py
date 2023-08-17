class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        hs = {}
        
        for n in nums:
            if n in hs.keys():
                hs[n] += 1
            else:
                hs[n] = 1
        
        return list(sorted(hs.items(), key = lambda x : x[1], reverse = True))[0][0]