class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        adj_list = [[] for _ in range(n)]
        ans = -1

        for node in roads:
            adj_list[node[0]].append(node[1])
            adj_list[node[1]].append(node[0])
        
        for i in range(n):
            for j in range(i+1, n):
                res = len(adj_list[i]) + len(adj_list[j])
                if j in adj_list[i]:
                    res -= 1
                ans = max(ans, res)

        return ans
