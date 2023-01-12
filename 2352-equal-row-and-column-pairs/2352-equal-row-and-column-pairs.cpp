class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            vector<int> tmp;
            for (int j = 0; j < grid.size(); j++) {
                tmp.push_back(grid[j][i]);
            }
            ans += count(begin(grid), end(grid), tmp);
        }
        return ans;
    }
};