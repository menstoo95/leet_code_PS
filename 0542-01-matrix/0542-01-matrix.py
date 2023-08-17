class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        delta = [[0,1],[0,-1],[1,0],[-1,0]]
        ans = [[-1 for _ in range(len(mat[0]))] for _ in range(len(mat))]
        n, m = len(mat), len(mat[0])
        q = []

        for i in range(n):
            for j in range(m):
                if mat[i][j] == 0:
                    ans[i][j] = 0
                    q.append([i, j])
        
        while q:
            r, c = q[0][0], q[0][1]
            q.pop(0)
            
            for i in range(4):
                nr, nc = r + delta[i][0], c + delta[i][1]

                if nr < n and nr >= 0 and nc < m and nc >= 0 and ans[nr][nc] == -1:
                    ans[nr][nc] = 1 + ans[r][c]
                    q.append([nr,nc])

        return ans

        