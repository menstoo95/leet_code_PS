class Solution:
    def minDeletions(self, s: str) -> int:
        cnt = sorted(Counter(s).values())
        s = set()
        ans = 0

        for a in cnt:
            while a in s and a>0:
                a -= 1
                ans += 1
            s.add(a)


        return ans
