class Solution:
    def decodeAtIndex(self, s: str, k: int) -> str:
        n = 0

        for c in s:
            if c.isdigit():
                n = n*int(c)
            else:
                n += 1

        for i in range(len(s)-1, -1, -1):
            if s[i].isdigit():
                n = n//int(s[i])
                k = k%n
            else:
                if k == 0 or n == k:
                    return s[i]
                n -= 1

        return ""