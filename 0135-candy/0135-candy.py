class Solution:
    def candy(self, ratings: List[int]) -> int:
        dp = [1 for _ in range(len(ratings))]
        n = len(ratings)

        for i in range(1, n):
            if ratings[i] > ratings[i-1] and dp[i] <= dp[i-1]:
                dp[i] = dp[i-1]+1
        
        for i in range(n-2, -1, -1):
            if ratings[i] > ratings[i+1] and dp[i] <= dp[i+1]:
                dp[i] = dp[i+1]+1
        
        return sum(dp)
                