class Solution {
public:
    int delta[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    int shortestBridge(vector<vector<int>>& grid) {
        int fr = -1, fc = -1;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    fr = i, fc = j;
                }
            }
            if(fr != -1)
                break;
        }
        
        
        queue<pair<int,int>> island, dist;
        
        island.push({fr,fc});
        dist.push({fr,fc});
        grid[fr][fc] = -1;
        while(!island.empty()){
            auto cur = island.front();
            island.pop();
            
            for(int i = 0; i < 4; i++){
                int nr = cur.first + delta[i][0];
                int nc = cur.second + delta[i][1];
                
                if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[cur.first].size() && grid[nr][nc] == 1){
                    island.push({nr, nc});
                    dist.push({nr,nc});
                    grid[nr][nc] = -1;
                }
            }
        }
        
        int ans = 0;
        while(!dist.empty()){
            queue<pair<int,int>> next;
            
            while(!dist.empty()){
                auto cur = dist.front();
                dist.pop();

                for(int i = 0; i < 4; i++){
                    int nr = cur.first + delta[i][0];
                    int nc = cur.second + delta[i][1];

                    if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[cur.first].size() && grid[nr][nc] != -1){
                        if(grid[nr][nc] == 1)
                            return ans;
                        else{
                            next.push({nr,nc});
                            grid[nr][nc] = -1;
                        }
                    }
                }
            }
            
            dist = next;
            ans++;
        }
        
        return ans;
    }
};

/*

[1,1,1,1,1]
[1,0,0,0,1]
[1,0,1,0,1]
[1,0,0,0,1]
[1,1,1,1,1]

*/