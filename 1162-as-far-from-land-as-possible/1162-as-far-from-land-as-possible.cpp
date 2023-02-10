class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1)
                    continue;
                grid[i][j] = 0x3f3f3f3f;
                if(i > 0)
                    grid[i][j] = min(grid[i][j], grid[i-1][j] + 1);
                if(j > 0)
                    grid[i][j] = min(grid[i][j], grid[i][j-1] + 1);
            }
        }
        
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(grid[i][j] == 1)
                    continue;
                if(i < n-1)
                    grid[i][j] = min(grid[i][j], grid[i+1][j] + 1);
                if(j < m-1)
                    grid[i][j] = min(grid[i][j], grid[i][j+1] + 1);
                ans = max(ans, grid[i][j]);
            }
        }
        
        return ans == 0x3f3f3f3f ? -1 : ans - 1;
    }
};