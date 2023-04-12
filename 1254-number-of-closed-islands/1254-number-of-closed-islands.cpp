class Solution {
public:
    int closedIsland(vector<vector<int>> grid)
    {
        int delta[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, ans = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));

        for (int i = 1; i < grid.size() - 1; i++)
        {
            for (int j = 1; j < grid[i].size() - 1; j++)
            {
                if (grid[i][j] == 0 && !visited[i][j])
                {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    bool flag = false;
                    while (!q.empty())
                    {
                        auto cur = q.front();
                        q.pop();

                        for (int d = 0; d < 4; d++)
                        {
                            int nr = cur.first + delta[d][0];
                            int nc = cur.second + delta[d][1];

                            if (nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size() || visited[nr][nc] || grid[nr][nc])
                                continue;
                            if ((nr == 0 || nc == 0 || nr == grid.size() - 1 || nc == grid[0].size() - 1) && grid[nr][nc] == 0)
                            {
                                flag = true;
                                continue;
                            }
                            q.push({nr, nc});
                            visited[nr][nc] = true;
                        }
                    }
                    if (!flag)
                        ans++;
                }
            }
        }

        return ans;
    }
};