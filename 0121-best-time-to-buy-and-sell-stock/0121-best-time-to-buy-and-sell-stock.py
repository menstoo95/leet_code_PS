class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mini = 0x3f3f3f3f
        ans = 0
        for price in prices:
            if price < mini:
                mini = price
            ans = max(ans, price-mini)

        return ans