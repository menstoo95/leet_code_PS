class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> hs;
        int n = grid.size(), ans = 0;
        
        for(int i = 0; i < n; i++)
            hs[grid[i]]++;
        
        for(int i = 0; i < n; i++){
            vector<int> res;
            for(int j = 0; j < n; j++)
                res.push_back(grid[j][i]);
            ans += hs[res];
        }
        
        
        return ans;
    }
};