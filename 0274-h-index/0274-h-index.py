class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort(key = lambda x : -x)

        for i in range(len(citations)):
            if i >= citations[i]:
                return i

        return len(citations)