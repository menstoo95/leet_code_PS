class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        res, ans = [], []
        for i, m in enumerate(mat):
            res.append((sum(m),i))
        
        res.sort()
        for i in range(k):
            ans.append(res[i][1])
        
        return ans