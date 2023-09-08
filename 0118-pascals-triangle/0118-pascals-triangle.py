class Solution:
    def generate(self, n: int) -> List[List[int]]:
        ans = []
        ans.append([1])

        for i in range(1, n):
            res = [1 for _ in range(i+1)]
            for j in range(1, i):
                res[j] = ans[i-1][j-1]+ans[i-1][j]

            ans.append(res)
        
        return ans
