class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        cur = -0x3f3f3f3f
        ans = 0
        
        for p in prices:
            a, b = cur, ans
            cur = max(a, b-p)
            ans = max(b, a+p)
            
        return ans;