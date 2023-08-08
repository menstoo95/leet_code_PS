class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        idx = 0
        ans = 0
        st = set()
    
        for c in s:
            while c in st:
                st.remove(s[idx])
                idx += 1
            st.add(c)
            ans = max(ans, len(st))
        
        return ans