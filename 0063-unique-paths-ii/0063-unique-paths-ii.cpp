class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
         for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!grid[i][j]){
                    if(!i && !j)
                        grid[i][j] ? dp[i][j] = 0 : dp[i][j] = 1;
                    else if(!i)
                        dp[i][j-1] ? dp[i][j] = 1 : dp[i][j] = 0;
                    else if(!j)
                        dp[i-1][j] ? dp[i][j] = 1 : dp[i][j] = 0;
                    else{
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    }
                }
            }
        }
        
        return dp[n-1][m-1];
            
    }
};