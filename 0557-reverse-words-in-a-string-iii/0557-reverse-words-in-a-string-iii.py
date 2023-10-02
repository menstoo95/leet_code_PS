class Solution:
    def reverseWords(self, s: str) -> str:
        asdf = list(s.split())
        ans = ""
        for a in asdf:
            ans += a[::-1] + " "

        return ans[:-1]