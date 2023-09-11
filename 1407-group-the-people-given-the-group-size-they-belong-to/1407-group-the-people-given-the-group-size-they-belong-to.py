class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        hs = defaultdict(list)

        for i, n in enumerate(groupSizes):
            hs[n].append(i)

        return [v[i:i+k] for k, v in hs.items() for i in range(0, len(v), k)]
        