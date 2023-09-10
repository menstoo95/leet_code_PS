class Solution:
    def countOrders(self, n: int) -> int:
        ans, MOD = 1, 1000000007

        for i in range(1, n+1):
            ans = ans * (i*2-1) * i % MOD
        
        return ans

