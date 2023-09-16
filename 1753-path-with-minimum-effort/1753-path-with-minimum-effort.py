class Solution:
    def __init__(self):
        self.vis = [[0] * 105 for _ in range(105)]
        self.dir = [(1, 0), (-1, 0), (0, -1), (0, 1)]

    def check(self, r, c, mid, heights):
        if not self.vis[r][c]:
            self.vis[r][c] = 1
            n, m = len(heights), len(heights[0])

            for i in range(4):
                nr, nc = r + self.dir[i][0], c + self.dir[i][1]

                if nr < 0 or nr >= n or nc < 0 or nc >= m:
                    continue

                if abs(heights[r][c] - heights[nr][nc]) <= mid:
                    self.check(nr, nc, mid, heights)

    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        l, r, n, m = 0, 1000000002, len(heights), len(heights[0])

        while l < r:
            mid = (l + r) // 2
            self.vis = [[0] * 105 for _ in range(105)]
            self.check(0, 0, mid, heights)

            if self.vis[n - 1][m - 1] == 1:
                r = mid
            else:
                l = mid + 1

        return l
        