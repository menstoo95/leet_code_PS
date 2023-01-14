class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> onerow(n);
        vector<int> onecol(m);
        
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    onerow[i] += 1;
                    onecol[j] += 1;
                }
            }
        }
        
        vector<vector<int>> ans(n,vector<int>(m,0));
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                ans[i][j] = onerow[i] + onecol[j] - (n - onerow[i]) - (m - onecol[j]);
            
        
        
        return ans;
    }
};