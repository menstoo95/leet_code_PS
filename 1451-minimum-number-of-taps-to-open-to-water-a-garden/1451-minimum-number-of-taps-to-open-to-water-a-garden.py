class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        dp = [0x3f3f3f3f for _ in range(n+1)]
        dp[0] = 0

        for i, a in enumerate(ranges):
            s, e = max(0, i-a), min(n, i+a)
            for j in range(s+1, e+1):
                dp[j] = min(dp[j], dp[s]+1)
        
        return dp[-1] if dp[-1] != 0x3f3f3f3f else -1
        