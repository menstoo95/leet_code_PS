class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        hs, ans = defaultdict(list), []

        for i, n in enumerate(groupSizes):
            hs[n].append(i)

        for k, v in hs.items():
            res = []
            for n in v:
                res.append(n)
                if len(res) >= k:
                    ans.append(res)
                    res = []
            
            if res:
                ans.append(res)
                
        return ans
        