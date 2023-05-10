class Solution {
public:
    int delta[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, -1));
        int dir = 0, idx = 1, r = 0, c = 0;
        
        while(idx <= n*n){
            ans[r][c] = idx;
            
            int nr = r + delta[dir][0];
            int nc = c + delta[dir][1];
            
            if(nr < n && nc < n && nr >= 0 && nc >= 0 && ans[nr][nc] == -1){
                r = nr, c = nc;
            }
            else{
                dir = (dir + 1) % 4;
                r = r + delta[dir][0];
                c = c + delta[dir][1];
            }
            
            idx++;
        }
        return ans;
        
    }
};