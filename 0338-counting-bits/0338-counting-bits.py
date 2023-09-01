class Solution:
    def countBits(self, n: int) -> List[int]:
        dp = [0 for _ in range(n+1)]
        
        for i in range(1, n+1):
            dp[i] = dp[i//2] + i%2
        
        return dp