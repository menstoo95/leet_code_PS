class Solution {
public:
    int delta[8][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }, { -1, 1 }, { -1, -1 }, { 1, -1 }, { 1, 1 } };
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1])
            return -1;
        queue<pair<int,int>> q;
        grid[0][0] = 1;
        q.push({0,0});
        
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            
            for(int i = 0; i < 8; i++){
                int nr = cur.first + delta[i][0];
                int nc = cur.second + delta[i][1];
                
                if(nr >= 0 && nc < n && nc >= 0 && nr < n && grid[nr][nc] == 0){
                    q.push({nr,nc});
                    grid[nr][nc] = grid[cur.first][cur.second] + 1;
                }
            }
        }
        
        for(auto a : grid){
            for(auto b : a)
                cout << b << " ";
            cout << endl;
        }
        
        return grid[n-1][n-1] ? grid[n-1][n-1] : -1;
    }
};